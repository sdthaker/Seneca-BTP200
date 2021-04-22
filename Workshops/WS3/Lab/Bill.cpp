// Workshop 3 Lab
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/01
//The below code is my own code and I have not taken any help in order to complete this workshop.

#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;

namespace sdds {

	double Bill::totalTax() const
	{
		double sum = 0.0;

		for (int i = 0; i < m_noOfItems; i++)
			sum += m_items[i].tax();

		return sum;
	}
	double Bill::totalPrice() const
	{
		double sum = 0;

		for (int i = 0; i < m_noOfItems; i++)
			sum += m_items[i].price();

		return sum;
	}
	void Bill::Title() const
	{
		cout << "+--------------------------------------+" << endl;

		if (isValid()) {
			
			cout << "| ";
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(36);
			cout << m_title;
			cout << " |" << endl;
		}

		else
			cout << "| Invalid Bill                         |" << endl;

		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;

	}
	void Bill::footer() const
	{
		cout << "+----------------------+---------+-----+" << endl;

		if (isValid()) {

			cout << "|                Total Tax: ";
			cout.setf(ios::right);
			cout.width(10);
			cout.precision(2);
			cout << totalTax();

			cout << " |" << endl;

			cout << "|              Total Price: ";
			cout.setf(ios::right);
			cout.width(10);
			cout.precision(2);
			cout << totalPrice();

			cout << " |" << endl;

			cout << "|          Total After Tax: ";
			cout.setf(ios::right);
			cout.width(10);
			cout.precision(2);
			cout << totalTax() + totalPrice();

			cout << " |" << endl;
		}

		else
			cout << "| Invalid Bill                         |" << endl;

		cout << "+--------------------------------------+" << endl;
	}

	void Bill::setEmpty()
	{
		m_title[0] = '\0';
		m_items = nullptr;
	}

	bool Bill::isValid() const
	{
		int counter = 0;
		bool check = false;

		if (m_title[0] != '\0' && m_items) {
			check = true;
			for (int i = 0; i < m_itemsAdded; i++)
				if (m_items[i].isValid())
					counter++;
		}
		return check && counter == m_noOfItems ? true : false;
	}

	void Bill::init(const char* title, int noOfItems)
	{
		if (title || noOfItems > 0) {
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);

			m_items = new Item[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++)
				m_items[i].setEmpty();
		}
		else
			setEmpty();
	}

	bool Bill::add(const char* item_name, double price, bool taxed)
	{
		bool ok = false;

		if (m_itemsAdded < m_noOfItems) {

			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded += 1;
			ok = true;
		}
		return ok;
	}

	void Bill::display() const
	{
		Title();

		for (int i = 0; i < m_noOfItems; i++)
			m_items[i].display();

		footer();
	}

	void Bill::deallocate()
	{
		delete[] m_items;
		m_itemsAdded = 0;
	}
}