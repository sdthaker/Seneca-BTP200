/* Citation and Sources...
Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.h
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

#ifndef SDDS_COVIDPATIENT_H
#define SDDS_COVIDPATIENT_H

#include <iostream>
#include "Patient.h" 

namespace sdds {

	class CovidPatient : public Patient {
	public:
		CovidPatient();
		char type() const;
		std::istream& csvRead(std::istream& is);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& is);
	};
}
#endif // !SDDS_COVIDPATIENT_H_



