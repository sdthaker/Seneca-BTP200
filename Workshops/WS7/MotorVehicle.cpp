// Workshop 7 Lab
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/03/15
//The below code is my own code except for professor provided code

#include <iostream>
#include <cstring>
#include "MotorVehicle.h"
#include "cstring.h"

using namespace std;

namespace sdds {
	
	MotorVehicle::MotorVehicle(const char plate[], const int year) {
		strCpy(m_plate, plate);
		strCpy(m_address, "Factory");
		m_year = year;
	}

	void MotorVehicle::moveTo(const char* address) {
		cout << '|';
		cout.width(8);
		cout << m_plate;
		cout << "| |";

		cout.width(20);
		cout << m_address;

		cout << " ---> ";

		cout.width(20);
		cout.setf(ios::left);
		if (strCmp(m_address, address))
			strCpy(m_address, address);
		cout << m_address;
		cout.unsetf(ios::left);

		cout << '|' << endl;
	}

	ostream& MotorVehicle::write(ostream& os)const {
		os << "| " << m_year << " | " << m_plate << " | " << m_address;
		return os;
	}

	istream& MotorVehicle::read(istream& is) {
		cout << "Built year: ";
		is >> m_year;

		cout << "License plate: ";
		is >> m_plate;

		cout << "Current location: ";
		is >> m_address;

		return is;
	}

	ostream& operator<<(ostream& os, const MotorVehicle& Ro) {
		return Ro.write(os);
	}

	istream& operator>>(istream& is, MotorVehicle& Ro) {
		return Ro.read(is);
	}
}