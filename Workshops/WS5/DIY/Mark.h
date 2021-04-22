// Workshop 5 DIY
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/14
//The below code is my own code and I have not taken any help in order to complete this workshop.

#ifndef SDDS_MARK_H
#define SDDS_MARK_H

namespace sdds {

	class Mark {
		int m_mark = 0;
		void setEmpty();
	public:
		Mark();
		Mark(int value);
		operator int() const;
		operator bool() const;
		Mark& operator+=(const int value);
		Mark& operator=(const int value);
		operator double() const;
		operator char() const;
	};
	int operator+=(int& value, const Mark& Ro);
}

#endif
