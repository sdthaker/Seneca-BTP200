/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.cpp
Author	Soham Thaker
Revision History
-----------------------------------------------------------
Date        Reason
2021/03/13  Preliminary release
2021/03/28  Updated read function to accept 0 as hour and min
2021/04/08	Updated the dates for revision history, since all the files had year as 2020
			Updated the logic for findTime function.
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include "Time.h"
#include "utils.h"
using namespace std;

namespace sdds {

	void Time::findTime(unsigned int& hour, unsigned int& min, 
						unsigned int val) const {

		while (hour % 60 != 0)
			hour -= 1;
		if (!val) {
			if (hour != m_min) {
				min = m_min - hour;
				hour /= 60;
			}
		}
		else {
			if (hour != val) {
				min = val - hour;
				hour /= 60;
			}
		}
		if (hour % 60 == 0)
			hour /= 60;
	}

	Time& Time::totalMinutes(char value,
		unsigned int val, unsigned int LoHour, unsigned int LoMin,
		unsigned int RoHour, unsigned int RoMin) {
		if (value == '-') {
			if (LoHour > RoHour)
				m_min = (LoHour * 60 + LoMin) - (RoHour * 60 + RoMin);
			else {
				while (LoHour < RoHour) LoHour += 24;
				m_min = (LoHour * 60 + LoMin) - (RoHour * 60 + RoMin);
			}
		}
		else if (value == '+') {
			m_min = (LoHour * 60 + LoMin) + (RoHour * 60 + RoMin);
		}
		else if (value == '*') {
			m_min *= val;
		}
		else if (value == '/') {
			m_min /= val;
		}
		return *this;
	}

	Time& Time::setToNow() {
		m_min = getTime();
		return *this;
	}

	Time::Time(unsigned int min) {
		m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const {
		
		unsigned int hour = m_min, min = 0;

		findTime(hour, min);
		
		ostr.width(2);
		ostr.fill('0');
		ostr << hour << ':';
		ostr.width(2);
		ostr.fill('0');
		ostr << min;

		return ostr;
	}

	istream& Time::read(istream& istr) {
		char colon = '\0';
		int hour = 0, min = 0;

		istr >> hour >> colon >> min;
		if (hour < 0 || colon != ':' || min < 0)
			istr.setstate(ios::failbit);
		else
			m_min = hour * 60 + min;

		return istr;
	}

	Time& Time::operator-=(const Time& D) {
		unsigned int LoHour = m_min, LoMin = 0, RoHour = D.m_min, RoMin = 0;

		findTime(LoHour, LoMin);
		D.findTime(RoHour, RoMin);

		totalMinutes('-', 10, LoHour, LoMin, RoHour, RoMin);
		return *this;
	}

	Time Time::operator-(const Time& D) const {
		Time T;
		unsigned int LoHour = m_min, LoMin = 0, RoHour = D.m_min, RoMin = 0;

		findTime(LoHour, LoMin);
		D.findTime(RoHour, RoMin);

		T.totalMinutes('-', 0, LoHour, LoMin, RoHour, RoMin);
		return T;
	}

	Time& Time::operator+=(const Time& D) {

		unsigned int LoHour = m_min, LoMin = 0, RoHour = D.m_min, RoMin = 0;

		findTime(LoHour, LoMin);
		D.findTime(RoHour, RoMin);

		totalMinutes('+', 0, LoHour, LoMin, RoHour, RoMin);
		return *this;
	}

	Time Time::operator+(const Time& D)const {
		Time T;
		unsigned int LoHour = m_min, LoMin = 0, RoHour = D.m_min, RoMin = 0;

		findTime(LoHour, LoMin);
		D.findTime(RoHour, RoMin);

		T.totalMinutes('+', 0, LoHour, LoMin, RoHour, RoMin);
		return T;
	}

	Time& Time::operator=(unsigned int val) {
		m_min = val;
		return *this;
	}

	Time& Time::operator*=(unsigned int val) {
		totalMinutes('*', val);
		return *this;
	}

	Time Time::operator*(unsigned int val)const {
		Time T(m_min);
		T.totalMinutes('*', val);
		return T;
	}

	Time& Time::operator/=(unsigned int val) {
		totalMinutes('/', val);
		return *this;
	}

	Time Time::operator/(unsigned int val)const {
		Time T(m_min);
		T.totalMinutes('/', val);
		return T;
	}

	Time::operator int()const {
		return (signed int)m_min;
	}

	Time::operator unsigned int()const {
		return m_min;
	}

	ostream& operator<<(ostream& ostr, const Time& D) {
		return D.write(ostr);
	}

	istream& operator>>(istream& istr, Time& D) {
		return D.read(istr);
	}
}