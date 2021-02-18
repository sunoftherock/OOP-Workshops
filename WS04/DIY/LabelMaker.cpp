// Workshop 4: DIY
// Date: 2/14/2021
// Author: Ruoqi Sun
// Student #: 135388205
// Class: OOP224
// I have done all the coding by myself and only copied the code that my professor provided to
// complete my workshops and assignments.
//
///////////////////////////////////////////////////
#include "LabelMaker.h"
#include "Label.h"
#include <iostream>


using namespace std;
namespace sdds {
	LabelMaker::LabelMaker(int noOfLabels) {

		//creates new memory for enough memory to hold array of Label[noOfLabels]
		m_noOfLabels = noOfLabels;
		labels = new Label[noOfLabels];
	}
	void LabelMaker::readLabels() {
		cout << "Enter " << m_noOfLabels << " labels:" << endl;
		for (int i = 0; i < m_noOfLabels; i++) {
			int number = i + 1;
			cout << "Enter label number " << number << endl;
			cout << "> ";
			labels[i].readLabel();
		}
	};
	void LabelMaker::printLabels() {
		for (int i = 0; i < m_noOfLabels; i++) {
			labels[i].printLabel() << endl;
		}
		};
	LabelMaker::~LabelMaker() {
		delete[] labels;
		labels = nullptr;
	}
}