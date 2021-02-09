// Workshop 3: DIY
// Date: 2/5/2021
// Author: Ruoqi Sun
// Student #: 135388205
// Class: OOP224
// I have done all the coding by myself and only copied the code that my professor provided to
// complete my workshops and assignments.
//
///////////////////////////////////////////////////

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;

namespace sdds {
	int i;

	void CalorieList::setEmpty() {
		foods = nullptr;
	};

	bool CalorieList::isValid()const {
		bool validity = true;
		if ((foods == nullptr)) {
			validity = false;
		}
		for (i = 0; i < c_noOfFoods; i++) {
			if (!(foods[i].isValid())) {
				validity = false;
			}
		};
		return validity;
	};

	int CalorieList::totalCal()const {
		int total_cal = 0;
		for (i = 0; i < c_noOfFoods; i++) {
			total_cal += foods[i].calorieNumber();
		};
		return total_cal;
	};

	ostream& CalorieList::Title(ostream& ostr)const {
		ostr << "+----------------------------------------------------+" << endl;
		if (isValid()) {
			ostr << "|  Daily Calorie Consumption                         |" << endl;
		}
		else {
			ostr << "| Invalid Calorie Consumption list                   |" << endl;
		};
		ostr << "+--------------------------------+------+------------+" << endl;
		ostr << "| Food name                      | Cals | When       |" << endl;
		ostr << "+--------------------------------+------+------------+" << endl;
		return ostr;
	};
	ostream& CalorieList::footer(ostream& ostr)const {
		ostr << "+--------------------------------+------+------------+" << endl;

		if (isValid()) {
			ostr << "|    Total Calories for today:";
			ostr << right;
			ostr.width(9);
			ostr << totalCal();
			ostr << " |            |" << endl;
		}
		else {
			ostr << "|    Invalid Calorie Consumption list                |" << endl;
		}
		ostr << "+----------------------------------------------------+" << endl;
		return ostr;
	};

	void CalorieList::init(int noOfFoods) {
		if (noOfFoods <= 0) {
			setEmpty();
		}
		else {
			c_noOfFoods = noOfFoods;
			c_foodsAdded = 0;
			foods = new Food[c_noOfFoods];
			for (i = 0; i < c_noOfFoods; i++) {
				foods[i].setEmpty();
			};
		};
	};
	bool CalorieList::add(const char* foodName, int calorieNumber, int eatingTime) {
		if (c_foodsAdded < c_noOfFoods) {
			foods[c_foodsAdded].set(foodName, calorieNumber, eatingTime);
			c_foodsAdded++;
			return true;
		};
		return false;
	};
	void CalorieList::display()const {
		Title();
		for (i = 0; i < c_noOfFoods; i++) {
			foods[i].display();
		}
		footer();

	};
	void CalorieList::deallocate() {
		for (i = 0; i < c_noOfFoods; i++) {
			delete[] foods;
			foods = nullptr;
		}
		c_noOfFoods = 0;
		c_foodsAdded = 0;
	};
}