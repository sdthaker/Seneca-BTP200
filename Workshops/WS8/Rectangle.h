// Workshop 8 Lab
// Name: Soham Thaker
// SID: 011-748-159
// Email: sdthaker1@myseneca.ca
// Date of Completion: 2021/03/22
// The below code is my own code except for professor provided code

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include <iostream>
#include "LblShape.h"

namespace sdds {
	class Rectangle : public LblShape {
		int m_width = 0;
		int m_height = 0;
	public:
		Rectangle() : LblShape() {}
		Rectangle(const char* label, int width, int height);
		operator bool() const;
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};
}
#endif