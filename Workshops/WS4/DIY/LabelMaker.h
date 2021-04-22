// Workshop 4 DIY
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/07
//The below code is my own code and I have not taken any help in order to complete this workshop.

#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"

namespace sdds {

	class LabelMaker {
		Label* m_label = nullptr;
		int m_noOfLabels = 0;
		void setLabel(int);
	public:
		LabelMaker();
		LabelMaker(int);
		~LabelMaker();
		void readLabels();
		void printLabels();
	};
}

#endif