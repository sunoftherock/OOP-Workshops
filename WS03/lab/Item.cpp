// Workshop 3: LAB
// Date: 2/4/2021
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
#include "Item.h"
using namespace std;

namespace sdds {

	void Item::setName(const char* name) {
		strnCpy(m_itemName, name, 20);
	}
	void Item::setEmpty() {
		m_price = 0.0;
		m_itemName[0] = '\0';
	};
	void Item::set(const char* name, double price, bool taxed) {
		if ((name == nullptr) || (price < 0.0) || (name[0] == '\0')) {
			setEmpty();
		}
		else {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		};
		
	};
	double Item::price()const {
		return m_price;
	};
	double Item::tax()const {
		if (m_taxed) {
			return m_price * 0.13;
		};
		return 0.0;
	};
	bool Item::isValid()const {
		return !((m_price <= 0.0) && (m_itemName[0] == '\0'));
	};
	void Item::display()const {
		if (isValid()) {
			cout << "| ";
			cout.fill('.');
			cout.width(20);
			cout << left;
			cout << m_itemName;
			cout << " | ";
			cout.width(7);
			cout << right;
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.fill(' ');
			cout << m_price;
			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);
			cout << " | ";
			if (m_taxed == true) {
				cout << "Yes";
			}
			else {
				cout << "No ";
			}
			cout << " |" << endl;
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	};

};