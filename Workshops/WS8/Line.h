// Workshop 8 Lab
// Name: Soham Thaker
// SID: 011-748-159
// Email: sdthaker1@myseneca.ca
// Date of Completion: 2021/03/22
// The below code is my own code except for professor provided code

#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include <iostream>
#include "LblShape.h"

namespace sdds {

	class Line : public LblShape{
		int m_length = 0;
	public:
		Line() : LblShape() {}
		Line(const char* label, const int length) :
			LblShape(label), m_length{ length }{}
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};
}

#endif