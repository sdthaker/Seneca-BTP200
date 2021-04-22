/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.cpp
Author	Soham Thaker
Revision History
-----------------------------------------------------------
Date        Reason
2021/03/18  Preliminary release
2021/04/08	Updated the dates for revision history, since all the files had year as 2020
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include <iostream>
#include "IOAble.h"

using namespace std;

namespace sdds {
	IOAble::~IOAble(){}

	ostream& operator<<(ostream& os, const IOAble& Ro) {
		return Ro.write(os);
	}

	istream& operator>>(istream& is, IOAble& Ro) {
		return Ro.read(is);
	}
}