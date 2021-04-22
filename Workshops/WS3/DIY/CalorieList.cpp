// Workshop 3 Lab
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/01
//The below code is my own code and I have not taken any help in order to complete this workshop.

#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;

namespace sdds {
	int CalorieList::totalCalories() const
	{
		int sum = 0;

		for (int i = 0; i < m_noOfItems; i++)
			sum += m_list[i].calories();

		return sum;
	}
	void CalorieList::Title() const
	{

		char validTitle[] = "Daily Calorie Consumption";
		char invalidTitle[] = "Invalid Calorie Consumption list";

		cout.width(53);
		cout.fill('-');
		cout.setf(ios::left);
		cout << '+';
		cout << '+' << endl;
		cout.fill(' ');

		if (isValid()) {
			cout << "|  ";
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(50);
			cout << validTitle;
			cout << "|" << endl;
		}

		else {
			cout << "| ";
			cout.setf(ios::left);
			cout.width(50);
			cout << invalidTitle;
			cout << " |" << endl;
		}

		cout.width(33);
		cout.fill('-');
		cout.setf(ios::left);
		cout << '+';
		cout << '+';
		cout.width(6);
		cout.fill('-');
		cout << '-';
		cout.width(13);
		cout.fill('-');
		cout.setf(ios::left);
		cout << '+';
		cout << '+' << endl;
		cout.fill(' ');
		cout << '|';
		cout.setf(ios::left);
		cout.width(32);
		cout.fill(' ');
		cout << " Food name";
		cout << '|';
		cout.width(6);
		cout.fill(' ');
		cout << " Cals";
		cout << '|';
		cout.width(12);
		cout.fill(' ');
		cout << " When";
		cout << '|' << endl;
		cout.width(33);
		cout.fill('-');
		cout.setf(ios::left);
		cout << '+';
		cout << '+';
		cout.width(6);
		cout.fill('-');
		cout << '-';
		cout.width(13);
		cout.fill('-');
		cout.setf(ios::left);
		cout << '+';
		cout << '+' << endl;
		cout.fill(' ');
	}
	void CalorieList::footer() const
	{
		cout.width(33);
		cout.fill('-');
		cout.setf(ios::left);
		cout << '+';
		cout << '+';
		cout.width(6);
		cout.fill('-');
		cout << '-';
		cout.width(13);
		cout.fill('-');
		cout.setf(ios::left);
		cout << '+';
		cout << '+' << endl;
		cout.fill(' ');

		if (isValid()) {

			cout << '|';
			cout.width(29);
			cout.fill(' ');
			cout.setf(ios::right);
			cout << "Total Calories for today:";
			cout.width(9);
			cout.fill(' ');
			cout << totalCalories();
			cout << " |";
			cout.width(12);
			cout.fill(' ');
			cout << ' ';
			cout << '|' << endl;
		}

		else {
			cout << '|';
			cout.width(52);
			cout.fill(' ');
			cout << "    Invalid Calorie Consumption list";
			cout << '|' << endl;
		}

		cout.width(53);
		cout.fill('-');
		cout.unsetf(ios::right);
		cout.setf(ios::left);
		cout << '+';
		cout << '+' << endl;
		cout.fill(' ');
	}

	void CalorieList::setEmpty()
	{
		m_list = nullptr;
	}

	bool CalorieList::isValid() const
	{
		int counter = 0;
		bool check = false;

		if (m_list) {
			check = true;
			for (int i = 0; i < m_itemsAdded; i++)
				if (m_list[i].isValid())
					counter++;
		}
		return check && counter == m_noOfItems ? true : false;
	}
	void CalorieList::init(int size)
	{
		if (size > 0) {
			m_noOfItems = size;
			m_itemsAdded = 0;

			m_list = new Food[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++)
				m_list[i].setEmpty();
		}
		else
			setEmpty();
	}
	bool CalorieList::add(const char* item_name, int calories, int when)
	{
		bool ok = false;

		if (m_itemsAdded < m_noOfItems) {

			m_list[m_itemsAdded].set(item_name, calories, when);
			m_itemsAdded += 1;
			ok = true;
		}
		return ok;
	}
	void CalorieList::display() const
	{
		Title();

		for (int i = 0; i < m_noOfItems; i++)
			m_list[i].display();

		footer();
	}
	void CalorieList::deallocate()
	{
		delete[] m_list;
		m_itemsAdded = 0;
	}
}