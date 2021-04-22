/* Citation and Sources...
Final Project Milestone 3
Module: Time
Filename: Time.h
Author	Soham Thaker
Revision History
-----------------------------------------------------------
Date        Reason
2021/03/13  Preliminary release
2021/04/08	Updated the dates for revision history, since all the files had year as 2020
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_TIME_H
#define SDDS_TIME_H
#include <iostream>

namespace sdds {
   class Time {
      unsigned int m_min;
      void findTime(unsigned int& hour, unsigned int& min, 
                    unsigned int val = 0) const;
      Time& totalMinutes(char value = '\0', unsigned int val = 0, 
            unsigned int LoHour = 0, unsigned int LoMin = 0, 
            unsigned int RoHour = 0, unsigned int RoMin = 0);
   public:
      Time& setToNow();
      Time(unsigned int min = 0);
      std::ostream& write(std::ostream& ostr) const;
      std::istream& read(std::istream& istr);

      Time& operator-=(const Time& D);
      Time operator-(const Time& D)const;
      Time& operator+=(const Time& D);
      Time operator+(const Time& D)const;

      Time& operator=(unsigned int val);
      Time& operator *= (unsigned int val);
      Time& operator /= (unsigned int val);
      Time operator *(unsigned int val)const;
      Time operator /(unsigned int val)const;

      operator unsigned int()const;
      operator int()const;
   };
   std::ostream& operator<<(std::ostream& ostr, const Time& D);
   std::istream& operator>>(std::istream& istr, Time& D);
}

#endif // !SDDS_TIME_H

