// Workshop 4 Lab
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/07
//The below code is my own code and I have not taken any help in order to complete this workshop.

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <cstring>
#include "cstring.h" 
#include "Canister.h"
const double PI = 3.14159265;

using namespace std;
namespace sdds {

	void Canister::setToDefault()
	{
		m_hieght = 13.0;
		m_diameter = 10.0;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	void Canister::setName(const char* Cstr)
	{
		if (Cstr && m_usable) {
			delete[] m_contentName;
			m_contentName = new char[strLen(Cstr) + 1];
			strCpy(m_contentName, Cstr);
		}
	}

	bool Canister::isEmpty() const
	{
		bool ok = false;
		if (m_contentVolume < 0.00001)
			ok = true;
		return ok;
	}

	bool Canister::hasSameContent(const Canister& C) const
	{
		bool ok = false;

		if (m_contentName && C.m_contentName)
			ok = strCmp(m_contentName, C.m_contentName);

		return !ok;
	}

	Canister::Canister()
	{
		setToDefault();
	}

	Canister::Canister(const char* contentName) 
	{
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double hieght, double diameter, const char* contentName)
	{
		if ((hieght >= 10.0 && hieght <= 40.0) && 
			(diameter >= 10.0 && diameter <= 30.0)) {

			m_hieght = hieght;
			m_diameter = diameter;

			if (contentName)
				setName(contentName);
			else
				m_contentName = nullptr;

			m_contentVolume = 0.0;
		}
		else {
			setToDefault();
			m_usable = false;
		}
	}

	Canister::~Canister()
	{
		delete[] m_contentName;
	}

	Canister& Canister::setContent(const char* contentName)
	{
		if (!contentName)
			m_usable = false;
		else if (isEmpty())
			setName(contentName);
		else if(strCmp(m_contentName, contentName))
			m_usable = false;

		return *this;
	}

	Canister& Canister::pour(double quantity)
	{
		if (m_usable && quantity > 0 &&
			(quantity + m_contentVolume <= capacity()))
			m_contentVolume += quantity;
		else
			m_usable = false;
		return *this;
	}

	Canister& Canister::pour(Canister& C)
	{
		bool ok = isEmpty();
		double vol = 0.0;
		double cap = capacity();

		if (ok)
			setContent(C.m_contentName);
		else
		{
			if (!hasSameContent(C)) {
				if (m_contentVolume)
					vol = m_contentVolume;
				clear();
				m_usable = false;
			}
		}

		if (C.m_contentVolume > cap - m_contentVolume) {
			if (vol)
				C.m_contentVolume -= cap - vol;
			else
				C.m_contentVolume -= cap - m_contentVolume;

			m_contentVolume = cap;
		}
		else {
			pour(C.m_contentVolume);
			C.m_contentVolume = 0.0;
		}
		return *this;
	}

	double Canister::volume() const
	{
		return m_contentVolume;
	}

	std::ostream& sdds::Canister::display() const
	{
		cout.setf(ios::fixed);
		cout.width(7);
		cout.precision(1);
		cout << capacity() << "cc (" << m_hieght 
			 << "x" << m_diameter << ") Canister";
		
		if (!m_usable)
			cout << " of Unusable content, discard!";
		else if(m_contentName) {
			cout << " of ";
			cout.width(7);
			cout.setf(ios::right);
			cout.fill(' ');
			cout << m_contentVolume << "cc   " << m_contentName;
		}
		return cout;
	}

	double Canister::capacity() const
	{
		return (PI * (m_hieght - 0.267) * (m_diameter / 2) * (m_diameter / 2));
	}

	void Canister::clear()
	{
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true; 
	}
}