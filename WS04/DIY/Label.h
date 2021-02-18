// Workshop 4: DIY
// Date: 2/14/2021
// Author: Ruoqi Sun
// Student #: 135388205
// Class: OOP224
// I have done all the coding by myself and only copied the code that my professor provided to
// complete my workshops and assignments.
//
///////////////////////////////////////////////////
#ifndef LABEL_H
#define LABEL_H
#include <iostream>

namespace sdds {
	class Label {
		char m_frame[9];
		char* m_content = nullptr;
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		//destructor;
		~Label();
		void readLabel();
		std::ostream& printLabel()const;
	};
};
#endif // !SDDS_SUBJECT_H