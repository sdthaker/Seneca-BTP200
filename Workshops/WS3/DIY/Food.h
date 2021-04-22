// Workshop 3 Lab
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/01
//The below code is my own code and I have not taken any help in order to complete this workshop.

#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H

namespace sdds {

	class Food {
		char m_fName[31];
		int m_cNumber;
		int m_time;
		void setName(const char* name);
	public:
		void setEmpty();
		void set(const char* fName, int cNumber, int m_time);
		void display()const;
		bool isValid()const;
		int calories()const;
	};
}

#endif

