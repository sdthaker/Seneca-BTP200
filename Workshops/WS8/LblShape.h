// Workshop 8 Lab
// Name: Soham Thaker
// SID: 011-748-159
// Email: sdthaker1@myseneca.ca
// Date of Completion: 2021/03/22
// The below code is my own code except for professor provided code

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include <iostream>
#include "Shape.h"

namespace sdds {

	class LblShape: public Shape{
		char* m_label = nullptr;
		void DMA(const char* label);
	protected:
		const char* label() const;
	public:
		LblShape() {};
		LblShape(const char* label);
		~LblShape();
		LblShape(const LblShape& Ro) = delete;
		LblShape& operator=(const LblShape& Ro) = delete;
		void getSpecs(std::istream& is);
	};
}

#endif
