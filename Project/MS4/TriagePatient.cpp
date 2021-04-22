/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.cpp
Author	Soham Thaker
Revision History
-----------------------------------------------------------
Date        Reason
2021/03/28  Preliminary release
2021/04/08	Updated the dates for revision history, since all the files had year as 2020
----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include "TriagePatient.h"
#include "utils.h"

using namespace std;

namespace sdds {
	int nextTriageTicket = 1;

	TriagePatient::TriagePatient() : Patient(nextTriageTicket) {
		m_symptoms = nullptr;
		nextTriageTicket++;
	}

	TriagePatient::~TriagePatient() {
		delete[] m_symptoms;
	}

	char TriagePatient::type() const {
		return 'T';
	}

	ostream& TriagePatient::csvWrite(ostream& os)const {
		return Patient::csvWrite(os) << ',' << m_symptoms;
	}

	ostream& TriagePatient::write(ostream& os) const {
		if (fileIO())
			csvWrite(os);
		else {
			os << "TRIAGE" << endl;
			Patient::write(os) << endl << "Symptoms: " << m_symptoms << endl;
		}
		return os;
	}

	void TriagePatient::DMA(bool check, istream& is){
		char* symptoms = nullptr;

		if (check)
			symptoms = getcstr("Symptoms: ");
		else
			symptoms = getcstr(nullptr, is);

		delete[] m_symptoms;
		if (symptoms) {
			m_symptoms = new char[strlen(symptoms) + 1];
			strcpy(m_symptoms, symptoms);
		}
		delete[] symptoms;
	}
 
   istream& TriagePatient::cfRead(istream& is, bool flag) {
	 
	   if (flag) {
		   Patient::csvRead(is);
		   is.ignore();
		   DMA(false, is);
		   nextTriageTicket = number() + 1;
	   }
	   else{
		   if (fileIO())
			   csvRead(is);
		   else {
			   Patient::read(is);
			   DMA(true);
		   }
	   }
	   return is;
   }

   istream& TriagePatient::csvRead(istream& is) {
	  return cfRead(is, true);
   }

   istream& TriagePatient::read(istream& is) {
	   return cfRead(is);
   }
}