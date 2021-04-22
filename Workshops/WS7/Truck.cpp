// Workshop 7 Lab
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/03/15
//The below code is my own code except for professor provided code

#include <iostream>
#include "Truck.h"

using namespace std;

namespace sdds {

	Truck::Truck(const char plate[], const int year, const double capacity, const char address[]) : MotorVehicle(plate, year){
		m_capacity = capacity;
		m_load = 0;
		moveTo(address);
	}

	bool Truck::addCargo(double cargo) {
		bool check = false;

		if (m_load != m_capacity) {
			m_load += cargo;
			if (m_load < m_capacity)
				check = true;
			else if (m_load > m_capacity) {
				m_load = m_capacity;
				check = true;
			}
		}
		return check;
	}

	bool Truck::unloadCargo() {
		bool check = false;

		if (m_load != 0) {
			m_load = 0;
			check = true;
		}
		return check;
	}

	std::ostream& Truck::write(std::ostream& os) const {
		MotorVehicle::write(os) << " | "<< m_load << '/' << m_capacity;
		return os;
	}

	std::istream& Truck::read(std::istream& is) {
		MotorVehicle::read(is);

		cout << "Capacity: ";
		is >> m_capacity;

		cout << "Cargo: ";
		is >> m_load;

		return is;
	}

	std::ostream& operator<<(std::ostream& os, const Truck& Ro) {
		return Ro.write(os);
	}

	std::istream& operator>>(std::istream& is, Truck& Ro) {
		return Ro.read(is);
	}
}