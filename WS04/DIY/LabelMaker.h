// Workshop 4: DIY
// Date: 2/14/2021
// Author: Ruoqi Sun
// Student #: 135388205
// Class: OOP224
// I have done all the coding by myself and only copied the code that my professor provided to
// complete my workshops and assignments.
//
///////////////////////////////////////////////////
#ifndef LABELMAKER_H
#define LABELMAKER_H
#include "Label.h"

namespace sdds {
	class LabelMaker {
		Label* labels;
		int m_noOfLabels;
	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};
}
#endif // !SDDS_SUBJECT_H