#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;

   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   bool load(Employee &ind_emp) {
      bool ok = false;
      char name[128];
      if (read(ind_emp.m_empNo) && read(ind_emp.m_salary) && read(name)){
         int actual_length = strLen(name)+1;
         ind_emp.m_name = new char[actual_length];
         strnCpy(ind_emp.m_name, name, actual_length);
         ok = true;
      }
      return ok;
   }

   bool load() {
      bool ok = true;
      int i = 0;
      if (openFile(DATAFILE)) {
         noOfEmployees = noOfRecords();
         employees = new Employee[noOfEmployees];
        for (i = 0; i < noOfEmployees; i++){
           if (load(employees[i])==false){
              ok = false;
           }
        }
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      if (ok == false){
         cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
      }
      return ok;
   }

   // TODO: Implementation for the display functions go here

   void display(Employee &ind_emp){
      cout << ind_emp.m_empNo << ":" << ind_emp.m_name << ind_emp.m_salary << endl;
   }

   void display(){
      int i = 0;
      cout << "Employee Salary report, sorted by employee number" << endl;
      cout << "no- Empno, Name, Salary" << endl;
      cout << "------------------------------------------------" <<endl;
      sort();
      for (i = 0; i < noOfEmployees; i++){
         cout << i << "- ";
         display(employees[i]);
      };
   };



   // TODO: Implementation for the deallocateMemory function goes here



}