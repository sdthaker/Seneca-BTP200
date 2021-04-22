/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
Author	Soham Thaker
Revision History
-----------------------------------------------------------
Date        Reason
2021/03/18  Preliminary release
2021/03/24  Updated >> operator overload to use 
            pre existing getInt() function from utils.cpp
2021/04/08	Updated the dates for revision history, since all the files had year as 2020
2021/04/11	Updated the Menu.cpp file to include utils.h from Menu.h

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/


#include <iostream>
#include <cstring>
#include "Menu.h"
#include "utils.h"

using namespace std;

namespace sdds {
	
	Menu::Menu(const char* MenuContent, int NoOfSelections) 
			  : m_noOfSel{NoOfSelections} {
		delete[] m_text;
		m_text = new char[strlen(MenuContent) + 1];
		strcpy(m_text, MenuContent);
	}

	Menu::~Menu() {
		delete[] m_text;
	}

	void Menu::display()const {
		cout << m_text << endl;
		cout << "0- Exit" << endl;
	}

	int& Menu::operator>>(int& Selection) {
		display();

		Selection = getInt(0, m_noOfSel, "> ", "Invalid option ", true);

		return Selection;
	}
}