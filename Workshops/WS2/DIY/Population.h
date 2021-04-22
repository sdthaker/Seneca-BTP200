// Workshop 2 DIY
// Name: Soham Thaker
// SID: 011-748-159
// Email: sdthaker1@myseneca.ca
// Date of Completion: 2021/01/24
//The below code is my own code and I have not taken any help in order to complete this workshop.

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {

	struct Population {
		char* m_postalCode;
		int m_population;
	};

	bool load(Population& emp);
	bool load(const char filename[]);
	void display();
	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_