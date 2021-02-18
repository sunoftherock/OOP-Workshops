// Workshop 4: DIY
// Date: 2/14/2021
// Author: Ruoqi Sun
// Student #: 135388205
// Class: OOP224
// I have done all the coding by myself and only copied the code that my professor provided to
// complete my workshops and assignments.
//
///////////////////////////////////////////////////

#include <iostream>
#include "Label.h"
#include "cstring.h"

using namespace std;
namespace sdds {
	Label::Label() {
		strCpy(m_frame, "+-+|+-+|");
	}
	Label::Label(const char* frameArg) {
		strCpy(m_frame, frameArg);
	}
	Label::Label(const char* frameArg, const char* content) {
		strCpy(m_frame, frameArg);
		m_content = new char[strLen(content) + 1];
		strCpy(m_content, content);
	}
	Label::~Label() {
		delete[] m_content;
		m_content = nullptr;
	}
	void Label::readLabel() {
		char temp[70];
		cin.getline(temp,71);
		m_content = new char[strLen(temp) + 1];
		strCpy(m_content, temp);

	}
	ostream& Label::printLabel()const {
		int length = strLen(m_content);

		if (length != 0) {
			//prints the top line border
			cout << m_frame[0];
			cout.width(length + 3);
			cout.fill(m_frame[1]);
			cout << m_frame[2] << endl;
			//prints the line with empty spaces in between
			cout << m_frame[7];
			cout.width(length + 3);
			cout.fill(' ');
			cout << right;
			cout << m_frame[3] << endl;
			//prints the line with the label inside the middle
			cout << m_frame[7] << " " << m_content << " " << m_frame[3] << endl;
			//prints the line with empty spaces in between
			cout << m_frame[7];
			cout.width(length + 3);
			cout.fill(' ');
			cout << right;
			cout << m_frame[3] << endl;
			//prints final frame bottom
			cout << m_frame[6];
			cout.width(length + 3);
			cout.fill(m_frame[1]);
			cout << m_frame[0];
		};
		return cout;
	};
}