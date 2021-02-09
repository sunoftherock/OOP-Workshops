// Workshop 3: LAB
// Date: 2/4/2021
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
#include "Bill.h"
using namespace std;
namespace sdds {
	int i;

	void Bill::setEmpty() {
		m_title[0] = '\0';
		m_items = nullptr;
	};

	bool Bill::isValid()const {
		bool validity = true;	
		if ((m_items == nullptr ||m_title[0] == '\0')) {
			validity = false;
		}
		for (i = 0; i < m_noOfItems && validity; i++) {
			if (!(m_items[i].isValid())) {
				validity = false;
			}
		};
		return validity;
	};

	double Bill::totalTax()const {
		double total_tax = 0.0;
		for (i = 0; i < m_noOfItems; i++) {
			m_items[i].tax() ? total_tax += m_items[i].tax() : total_tax;
		};
		return total_tax;
	};

	double Bill::totalPrice()const {
		double total_price = 0.0;
			for (i = 0; i < m_noOfItems; i++) {
				m_items[i].price() ? total_price += m_items[i].price() : total_price;
			};
		return total_price;
	};

	void Bill::Title()const {
		cout << "+--------------------------------------+" << endl;
		if (isValid()) {
			cout << "| ";
			cout.width(36);
			cout << left;
			cout << m_title;
			cout << " |" << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		};
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	};
	void Bill::footer()const {
		cout << "+----------------------+---------+-----+" << endl;

		if (isValid()) {
			cout << "|                Total Tax: ";
			cout << right;
			cout.width(10);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalTax();
			cout << " |" << endl;
			cout << "|              Total Price: ";
			cout.width(10);
			cout.precision(2);
			cout << totalPrice();
			cout << " |" << endl;
			cout << "|          Total After Tax: ";
			cout.width(10);
			cout.precision(2);
			cout << (totalTax() + totalPrice());
			cout << " |" << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+--------------------------------------+" << endl;
	};

	void Bill::init(const char* title, int noOfItems) {
		if (!(title) || (noOfItems <= 0)) {
			setEmpty();
		}
		else {
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);
			m_items = new Item[m_noOfItems];
			for (i = 0; i < noOfItems; i++) {
				m_items[i].setEmpty();
			};
		};
	};
	bool Bill::add(const char* item_name, double price, bool taxed) {
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			return true;
		};
		return false;
	};
	void Bill::display()const {
		Title();
		for (i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer();

	};
	void Bill::deallocate() {
		for (i = 0; i < m_noOfItems; i++) {
			delete[] m_items;
			m_items = nullptr;
		}
	m_noOfItems = 0;
	m_itemsAdded = 0;
	};
}