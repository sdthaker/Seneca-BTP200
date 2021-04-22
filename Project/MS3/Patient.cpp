/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.cpp
Author	Soham Thaker
Revision History
-----------------------------------------------------------
Date        Reason
2021/03/23  Preliminary release
2021/04/08	Updated the dates for revision history, since all the files had year as 2020
2021/04/11	Updated the Patient.cpp file to include utils.h from patient.h

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include "Patient.h"
#include "utils.h"

using namespace std;

namespace sdds {

	Patient::~Patient() {
		delete[] m_name;
	}

	bool Patient::fileIO() const {
		return m_flag;
	}

	void Patient::fileIO(bool flag) {
		m_flag = flag;
	}

	bool Patient::operator==(char check) const {
		if (check == type())
			return true;
		else
			return false;
	}

	bool Patient::operator==(const Patient& Ro) const {
		if (type() == Ro.type())
			return true;
		else
			return false;
	}

	void Patient::setArrivalTime() {
		m_ticket.resetTime();
	}

	Patient::operator Time() const {
		return Time(m_ticket);
	}

	int Patient::number() const {
		return m_ticket.number();
	}

	ostream& Patient::csvWrite(ostream& os)const {
		os << type() << "," << m_name << "," << m_number << ",";
		m_ticket.csvWrite(os);
		return os;
	}

	ostream& Patient::write(ostream& os) const {
		int i = 0;
		os << m_ticket << endl;
		while (i != 25 && m_name[i] != '\0')
			os << m_name[i++];
		os << ", OHIP: " << m_number; 
		return os;
	}


	void Patient::DMA(const char* name) {
		if (name && name[0] != '\0') {
			delete[] m_name;
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
	}

	istream& Patient::cfRead(istream& is, bool flag) {

		char* og = nullptr;

		if (flag)
			og = getcstr("Name: ", is, '\n');
		else
			og = getcstr(nullptr, is, ',');
		
		DMA(og);

		if (!flag) {
			is >> m_number;
			is.ignore();
			m_ticket.csvRead(is);
		}
		else {
			m_number = getInt(100000000, 999999999, "OHIP:",
							 "Invalid OHIP Number, ", true);
		}
		delete[] og;
		return is;
	}

	istream& Patient::csvRead(istream& is) {
		return cfRead(is);
	}

	istream& Patient::read(istream& is) {
		return cfRead(is, true);
	}
}