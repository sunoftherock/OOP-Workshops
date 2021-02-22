// Workshop 5: DIY
// Date: 2/20/2021
// Author: Ruoqi Sun
// Student #: 135388205
// Class: OOP224
// I have done all the coding by myself and only copied the code that my professor provided to
// complete my workshops and assignments.
//
///////////////////////////////////////////////////
#include "Mark.h"

using namespace std;
namespace sdds {

	// checks if number is in valid grade range
	bool in_range(int testNumber) {
		return (testNumber <= 100 && testNumber >= 0);
	}

	// tries to set the grade, if within range. Otherwise, will set it invalid.
	void Mark::setGrade(int grade) {
		if (in_range(grade)) {
			m_grade = grade;
		}
		else m_grade = -1;
	}

	// checks if m_grade is != -1, i.e. checks if Mark object is valid
	bool Mark::operator ~() const {
		return (m_grade != -1);
	}

	//blank initializer
	Mark::Mark() {
		m_grade = 0;
	}

	//initialized to an int
	Mark::Mark(int number) {
		setGrade(number);
	}

	// will return a valid mark or 0 if invalid
	Mark::operator int() const {
		if (~*this) {
			return m_grade;
		}
		return 0;
	}

	Mark& Mark::operator +=(int addedVal) {
		if (~*this && in_range(addedVal)) {
			int total = m_grade + addedVal;
			setGrade(total);
		}
		return *this;
	}

	Mark& Mark::operator =(int setTo) {
		setGrade(setTo);
		return *this;
	}

	Mark::operator double() const {
		if (m_grade >= 80 && m_grade <= 100) {
			return 4.0;
		}
		else if (m_grade >= 70 && m_grade < 80) {
			return 3.0;
		}
		else if (m_grade >= 60 && m_grade < 70) {
			return 2.0;
		}
		else if (m_grade >= 50 && m_grade < 60) {
			return 1.0;
		}
		else if (m_grade >= 0 && m_grade < 50) {
			return 0.0;
		}
		else return 0.0;
	}

	Mark::operator char() const {
		if (m_grade >= 80 && m_grade <= 100) {
			return 'A';
		}
		else if (m_grade >= 70 && m_grade < 80) {
			return 'B';
		}
		else if (m_grade >= 60 && m_grade < 70) {
			return 'C';
		}
		else if (m_grade >= 50 && m_grade < 60) {
			return 'D';
		}
		else if (m_grade >= 0 && m_grade < 50) {
			return 'F';
		}
		else return 'X';
	}

	int operator +=(int& integer, const Mark& mark) {
		if (~mark) {
			integer += (int)mark;
			return integer;
		}
		return integer;
	}
	


}