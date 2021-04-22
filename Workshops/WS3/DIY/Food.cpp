// Workshop 3 Lab
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/01
//The below code is my own code and I have not taken any help in order to complete this workshop.

#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;

namespace sdds {

	void Food::setName(const char* name)
	{
		//int len = strLen(name);
		strnCpy(m_fName, name, 30);
		m_fName[30] = '\0';
	}

	void Food::setEmpty()
	{
		m_cNumber = -1;
		m_fName[0] = '\0';
		m_time = 0;
	}

	void Food::set(const char* fName, int cNumber, int time)
	{
		if ((cNumber < 0 || cNumber > 3000) || !fName || (time < 1 || time > 4))
			setEmpty();
		else {
			setName(fName);
			m_cNumber = cNumber;
			m_time = time;
		}
	}

	void Food::display() const
	{
		if (isValid()) {
			cout << "| ";
			cout.width(30);
			cout.fill('.');
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout << m_fName;
			cout << " | ";
			cout.setf(ios::right);
			cout.width(4);
			cout.fill(' ');
			cout << m_cNumber;
			cout << " | ";
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(10);

			switch (m_time) {
			case 1: 
				cout << "Breakfast";
				break;
			case 2: 
				cout << "Lunch";
				break;
			case 3:
				cout << "Dinner"; 
				break;
			case 4: 
				cout << "Snack";
				break;
			}
			cout << " |" << endl;
		}

		else {
			cout << "|";
			cout.width(31);
			cout.fill('x');
			cout << ' ';
			cout << " |";
			cout.width(5);
			cout.fill('x');
			cout << ' ';
			cout << " |";
			cout.width(11);
			cout.fill('x');
			cout << ' ';
			cout << " |" << endl;
			cout.fill(' ');
		}
	}

	bool Food::isValid() const
	{
		return m_cNumber == -1 && m_fName[0] == '\0' && !m_time ? false : true;
	}

	int Food::calories() const
	{
		return m_cNumber;
	}
}