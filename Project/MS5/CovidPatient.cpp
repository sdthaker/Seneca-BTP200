/* Citation and Sources...
Final Project Milestone 5
Module: CovidPatient
Filename: CovidPatient.cpp
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
#include "CovidPatient.h"

using namespace std;

namespace sdds {

   int nextCovidTicket = 1;

   CovidPatient::CovidPatient() : Patient(nextCovidTicket) {
	   nextCovidTicket++;
   }

   char CovidPatient::type() const{
	   return 'C';
   }

   istream& CovidPatient::csvRead(istream& is) {
	   Patient::csvRead(is);
	   nextCovidTicket = number() + 1;
	   is.ignore();
	   return is;
   }

   ostream& CovidPatient::write(ostream& os) const {
	   if (fileIO())
		   csvWrite(os);
	   else {
		   os << "COVID TEST" << endl;
		   Patient::write(os) << endl;
	   }
	   return os;
   }

   istream& CovidPatient::read(istream& is) {
	   if (fileIO())
		   csvRead(is);
	   else
		   Patient::read(is);
	   return is;
   }
}