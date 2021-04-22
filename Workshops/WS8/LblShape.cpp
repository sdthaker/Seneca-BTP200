// Workshop 8 Lab
// Name: Soham Thaker
// SID: 011-748-159
// Email: sdthaker1@myseneca.ca
// Date of Completion: 2021/03/22
// The below code is my own code except for professor provided code

#include <iostream>
#include <cstring>
#include "LblShape.h"

using namespace std;

namespace sdds {

	void LblShape::DMA(const char* label) {
		if (label && label[0] != '\0') {
			delete[] m_label;
			m_label = new char[strlen(label) + 1];
			strcpy(m_label, label);
		}
	}

	const char* LblShape::label() const {
		return m_label;
	}

	LblShape::LblShape(const char* label) {
		DMA(label);
	}

	LblShape::~LblShape() {
		delete[] m_label;
	}

	void LblShape::getSpecs(istream& is) {

		char buf[20] = { '\0' };
		char* og = nullptr, * tmp = nullptr;
		int size = 0;
		bool flag = true;

		while (flag) {

			is.get(buf, 20, ',');

			if (is) {
				int bufLen = strlen(buf);

				tmp = new char[size + bufLen + 1];

				if (og)
					strncpy(tmp, og, size);
				strncpy(&tmp[size], buf, bufLen);

				tmp[bufLen + size] = '\0';

				delete[] og;
				og = tmp;
				tmp = nullptr;
				size += bufLen;

				if (bufLen < 19) {
					flag = false;
					is.clear();
					is.ignore();
				}
			}
		}
		DMA(og);
		delete[] og;
	}
}