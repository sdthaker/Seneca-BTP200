// Workshop 7 Lab
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/03/15
//The below code is my own code except for professor provided code

#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H

#include <iostream>
#include "MotorVehicle.h"

namespace sdds {

	class Truck : public MotorVehicle {
		double m_capacity = 0;
		double m_load = 0;
	public:
		Truck(const char plate[], const int year, const double capacity, const char address[]);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& is);
	};

	std::ostream& operator<<(std::ostream& os, const Truck& Ro);
	std::istream& operator>>(std::istream& is, Truck& Ro);
}

#endif