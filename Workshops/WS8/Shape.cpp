// Workshop 8 Lab
// Name: Soham Thaker
// SID: 011-748-159
// Email: sdthaker1@myseneca.ca
// Date of Completion: 2021/03/22
// The below code is my own code except for professor provided code

#include <iostream>
#include "Shape.h"

using namespace std;

namespace sdds {

	Shape::~Shape() {}

	ostream& operator<<(ostream& os, const Shape& Ro) {
		Ro.draw(os);
		return os;
	}

	istream& operator>>(istream& is, Shape& Ro) {
		Ro.getSpecs(is);
		return is;
	}
}