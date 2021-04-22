/* Citation and Sources...
Final Project Milestone 5
Module: TriagePatient
Filename:  TriagePatient.h
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
#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H

#include <iostream>
#include "Patient.h"

namespace sdds {

	class TriagePatient : public Patient {
		char* m_symptoms = nullptr;
		std::istream& cfRead(std::istream& is, bool flag = false);
	public:
		TriagePatient();
		~TriagePatient();
		char type() const;
		void DMA(bool check = false, std::istream& is = std::cin);
		std::ostream& csvWrite(std::ostream& os)const;
		std::istream& csvRead(std::istream& is);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& is);
	};
}
#endif // !SDDS_TRIAGEPATIENT_H


