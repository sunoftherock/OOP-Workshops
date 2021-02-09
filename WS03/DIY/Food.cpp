// Workshop 3: DIY
// Date: 2/5/2021
// Author: Ruoqi Sun
// Student #: 135388205
// Class: OOP224
// I have done all the coding by myself and only copied the code that my professor provided to
// complete my workshops and assignments.
//
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;


namespace sdds {

	void Food::setName(const char* name) {
		strnCpy(f_name, name, 30);
	};
	void Food::setEmpty() {
		f_name[0] = '\0';
	};
	void Food::set(const char* name, int calorieNumber, int eatingTime) {
		if ((name == nullptr) || (calorieNumber < 0) || (name[0] == '\0') || (calorieNumber > 3000) || (eatingTime > 4) || (eatingTime < 1)) {
			setEmpty();
		}
		else {
			setName(name);
			f_calorieNumber = calorieNumber;
			f_eatingTime = eatingTime;
		};
	};

	int Food::calorieNumber()const {
		return f_calorieNumber;
	};
	bool Food::isValid()const {
		return f_name[0] != '\0' && f_calorieNumber >= 0 && f_calorieNumber <= 3000 && f_eatingTime <= 4 && f_eatingTime >= 1;
	};

	ostream& Food::display(ostream& ostr)const {
		if (isValid()) {
			ostr << "| ";
			ostr.width(30);
			ostr << left;
			ostr.fill('.');
			ostr << f_name;
			ostr << " | ";
			ostr.width(4);
			ostr.fill(' ');
			ostr << right;
			ostr << f_calorieNumber;
			ostr << " | ";
			ostr << left;
			ostr.width(10);
			switch (f_eatingTime)
			{
			case 1:
				ostr << "Breakfast";
				break;
			case 2:
				ostr << "Lunch";
				break;
			case 3:
				ostr << "Dinner";
				break;
			case 4:
				ostr << "Snack";
				break;
			};
			ostr << " |" << endl;

		}
		else {
			ostr << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
		return ostr;
	};


};