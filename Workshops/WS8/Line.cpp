// Workshop 8 Lab
// Name: Soham Thaker
// SID: 011-748-159
// Email: sdthaker1@myseneca.ca
// Date of Completion: 2021/03/22
// The below code is my own code except for professor provided code

#include <iostream>
#include <iomanip>
#include "Line.h"

using namespace std;

namespace sdds {

	void Line::getSpecs(std::istream& is) {
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore(2000, '\n');
	}

	void Line::draw(std::ostream& os) const {
		if (m_length && label()) {
			cout << label() << endl;
			os << setw(m_length) << setfill('=') << '=';
		}
	}
}