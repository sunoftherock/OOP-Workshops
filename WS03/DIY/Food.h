#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
#include <iostream>

using namespace std;
namespace sdds {
    class Food {
        char f_name[31];
        int f_calorieNumber;
        int f_eatingTime;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int calorieNumber, int eatingTime);
        ostream& display(ostream& ostr = cout) const;
        bool isValid()const;
        int calorieNumber()const;
    };
};

#endif // !SDDS_SUBJECT_H