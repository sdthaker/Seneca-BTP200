/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.h
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

#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H

#include <iostream>
#include "IOAble.h"
#include "Ticket.h"

namespace sdds {
	class Patient: public IOAble {
		char* m_name = nullptr;
		int m_number = 0;
		Ticket m_ticket = 0;
		bool m_flag = false;
		void DMA(const char* name);
		std::istream& cfRead(std::istream& os, bool flag = false);
	public:
		Patient(int ticket = 0, bool flag = false) 
				: m_ticket(ticket), m_flag{ flag }{}
		Patient(const Patient& Ro) = delete;
		Patient& operator=(const Patient& Ro) = delete;
		~Patient();
		virtual char type() const = 0;
		bool fileIO() const;
		void fileIO(bool flag);
		bool operator==(char check) const;
		bool operator==(const Patient& Ro) const;
		void setArrivalTime();
		operator Time() const;
		virtual int number() const;
		std::ostream& csvWrite(std::ostream& os)const;
		std::istream& csvRead(std::istream& is);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& is);
	};
}

#endif