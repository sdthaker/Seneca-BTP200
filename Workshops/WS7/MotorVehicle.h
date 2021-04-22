// Workshop 7 Lab
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/03/15
//The below code is my own code except for professor provided code

#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

#include <iostream>

namespace sdds {
	
	class MotorVehicle {
		char m_plate[9] = { '\0' };
		char m_address[64] = { '\0' };
		int m_year = 0;
	public:
		MotorVehicle(const char plate[], const int year);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& is);
	};

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& Ro);
	std::istream& operator>>(std::istream& is, MotorVehicle& Ro);
}

#endif