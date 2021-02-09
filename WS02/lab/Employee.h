#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#define DATAFILE "employees.csv"
namespace sdds {
    struct Employee {
        char* m_name;
        int m_empNo;
        double m_salary;
    };
    void sort();

    bool load(Employee& ind_emp);
    bool load();

    void display(Employee& ind_emp);
    void display();

    void deallocateMemory();
}
#endif // SDDS_EMPLOYEE_H_