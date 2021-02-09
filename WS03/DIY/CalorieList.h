#ifndef SDDS_CALORIE_H_
#define SDDS_CALORIE_H_
#include "Food.h"
#include <iostream>


using namespace std;
namespace sdds {
    class CalorieList {
        char c_title[50];
        Food* foods;
        int c_noOfFoods;
        int c_foodsAdded;
        int totalCal()const;
        ostream& Title(ostream& ostr = cout)const;
        ostream& footer(ostream& ostr = cout)const;
        void setEmpty();
        bool isValid()const;
    public:
        void init(int noOfItems);
        bool add(const char* foodName, int calorieNumber, int eatingTime);
        void display()const;
        void deallocate();
    };
}
#endif // !SDDS_TRANSCRIPT_H
