// Workshop 5: DIY
// Date: 2/20/2021
// Author: Ruoqi Sun
// Student #: 135388205
// Class: OOP224
// I have done all the coding by myself and only copied the code that my professor provided to
// complete my workshops and assignments.
//
///////////////////////////////////////////////////

namespace sdds {
	class Mark {
		int m_grade;

	public:
		Mark();
		Mark(int number);
		operator int() const;
		operator double() const;
		operator char() const;
		Mark& operator +=(int addedVal);
		Mark& operator =(int setTo);
		bool operator ~() const;
		void setGrade(int testNumber);
	};
	int operator +=(int& integer, const Mark& mark);
	bool in_range(int testNumber);
};

