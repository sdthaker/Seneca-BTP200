// Workshop 3 Lab
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/01
//The below code is my own code and I have not taken any help in order to complete this workshop.

#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
#define hst 0.13

namespace sdds {

	void Item::setName(const char* name)
	{
		strnCpy(m_itemName, name, 20);
		m_itemName[20] = '\0';
	}

	void Item::setEmpty()
	{
		m_price = 0.0;
		m_itemName[0] = '\0';
	}

	void Item::set(const char* name, double price, bool taxed)
	{
		if (price < 0 || !name)
			setEmpty();
		else {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}

	void Item::display() const
	{
		if (isValid()) {
			cout << "| ";
			cout.width(20);
			cout.fill('.'); 
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout << m_itemName;
			cout << " | ";
			cout.setf(ios::right);
			cout.width(7);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.fill(' ');
			cout << m_price;
			cout << " | ";

			if (m_taxed)
				cout << "Yes";
			else
				cout << "No ";

			cout << " |" << endl;
		}

		else
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
	}

	bool Item::isValid() const
	{
		return m_price == 0.0 && m_itemName[0] == '\0' ? false : true;
	}

	double Item::price() const
	{
		return m_price;
	}

	double Item::tax() const
	{
		/*if (!m_taxed)
			return 0.0;
		else
			return m_price * hst;*/
		return !m_taxed ? 0.0 : m_price * hst;
	}
}