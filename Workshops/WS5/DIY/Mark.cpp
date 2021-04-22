// Workshop 5 DIY
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/14
//The below code is my own code and I have not taken any help in order to complete this workshop.

#define _CRT_SECURE_NO_WARNINGS
#include "Mark.h"

namespace sdds {

	void Mark::setEmpty() {
		m_mark = -1;
	}

	Mark::Mark() : Mark(0) { } //code reuse, calling 1 arg constructor onto the default ctor
		//m_mark = 0;

	Mark::Mark(int value) {
		m_mark = value;

		if (!*this) {
			m_mark = -1;
		}
	}

	Mark::operator bool() const {
		return m_mark >= 0 && m_mark <= 100;
	}

	Mark::operator int() const {
		return *this ? m_mark : 0;
	}

	Mark& Mark::operator+=(const int value) {
		if (*this)
			m_mark += value;
		return *this;
	}

	Mark& Mark::operator=(const int value){
		m_mark = value;
		if (!*this)
			setEmpty();
		return *this;
	}

	Mark::operator double() const {
		double value = 0.0;

		if (int(*this)) {
			if (m_mark >= 50 && m_mark < 60)
				value = 1.0;
			else if (m_mark >= 60 && m_mark < 70)
				value = 2.0;
			else if (m_mark >= 70 && m_mark < 80)
				value = 3.0;
			else if (m_mark >= 80 && m_mark <= 100)
				value = 4.0;
		}
		return value;
	}

	Mark::operator char() const {
		char grade = 'X';

		if (int(*this)) {
			if ((double)*this == 0.0)
				grade = 'F';
			else if ((double)*this == 1.0)
				grade = 'D';
			else if ((double)*this == 2.0)
				grade = 'C';
			else if ((double)*this == 3.0)
				grade = 'B';
			else if ((double)*this == 4.0)
				grade = 'A';
		}
		return grade;
	}

	int operator+=(int& value, const Mark& Ro) {
		return Ro ? value += int(Ro) : value;
	}
}