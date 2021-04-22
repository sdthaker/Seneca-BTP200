/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.h
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

#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H

#include <iostream>

namespace sdds {
	class IOAble {
	public:
		virtual std::ostream& csvWrite(std::ostream& os)const = 0;
		virtual std::istream& csvRead(std::istream& is) = 0;
		virtual std::ostream& write(std::ostream& os)const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		virtual ~IOAble();
	};
	std::ostream& operator<<(std::ostream& os, const IOAble& Ro);
	std::istream& operator>>(std::istream& is, IOAble& Ro);
}

#endif