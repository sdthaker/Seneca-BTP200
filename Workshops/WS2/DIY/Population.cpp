// Workshop 2 DIY
// Name: Soham Thaker
// SID: 011-748-159
// Email: sdthaker1@myseneca.ca
// Date of Completion: 2021/01/24
//The below code is my own code and I have not taken any help in order to complete this workshop.

#include <iostream>
#include "cstring.h"
#include "Population.h"
#include "File.h"

using namespace std;

namespace sdds {

	int noOfPostalCode;
	Population* population;

	void sort() {
		int i, j;
		Population temp;

		for (i = noOfPostalCode - 1; i > 0; i--) {

			for (j = 0; j < i; j++) {

				if (population[j].m_population > population[j + 1].m_population) {

					temp = population[j];
					population[j] = population[j + 1];
					population[j + 1] = temp;
				}
			}
		}
	}
	
	bool load(Population& popu) {
		bool ok = false;
		char PC[128];

		if (read(PC) && read(popu.m_population)) {

			popu.m_postalCode = new char[strLen(PC) + 1];
			strCpy(popu.m_postalCode, PC);

			ok = true;
		}
		return ok;
	}

	bool load(const char filename[]) {

		bool ok = false;
		int i = 0;

		if (openFile(filename)) {

			noOfPostalCode = noOfRecords();
			population = new Population[noOfPostalCode];

			int read = 0;

			for (i = 0; i < noOfPostalCode; i++) {

				if (load(population[i]))
					read += 1;
			}

			if (read == noOfPostalCode)
				ok = true;
			else
				cout << "Error: incorrect number of records read the data is possibly"
						" corrupted!" << endl;

			closeFile();
		}
		else
			cout << "Could not open data file: " << filename << endl;

		return ok;
	}

	void display() {

		int totalPopulation = 0;
		sort();

		cout << "Postal Code: population" 
			 << endl << "-------------------------" << endl;

		for (int i = 0; i < noOfPostalCode; i++) {

			cout << i + 1 << "- " << population[i].m_postalCode 
				 << ":  " << population[i].m_population << endl;
			totalPopulation += population[i].m_population;
		}
		cout << "-------------------------" << endl 
			 << "Population of Canada: " << totalPopulation << endl;
	}

	void deallocateMemory() {

		for (int i = 0; i < noOfPostalCode; i++) {
			delete[] population[i].m_postalCode;
			population[i].m_postalCode = nullptr;
		}
		delete[] population;
		population = nullptr;
	}
}