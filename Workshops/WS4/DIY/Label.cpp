// Workshop 4 DIY
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/07
//The below code is my own code and I have not taken any help in order to complete this workshop.

#include<iostream>
#include "cstring.h"
#include "Label.h"

using namespace std;

namespace sdds {

	void Label::setToDefault(const char* arr) 
	{
		strCpy(m_frame, arr);
		m_text = nullptr;
		m_empty = false;
	}

	Label::Label()
	{
		//setToDefault();

		strCpy(m_frame, "+-+|+-+|");
		m_empty = false;
	}

	Label::Label(const char* frameArg) : Label()
	{
		if (frameArg && strLen(frameArg) <= 8) {
			m_empty = false;
			strCpy(m_frame, frameArg);

			//setToDefault(frameArg);
		}
	} 

	Label::Label(const char* frameArg, const char* content) : Label()
	{
		if (frameArg && content && strLen(frameArg) <= 8) {

			//setToDefault(frameArg);
			strCpy(m_frame, frameArg);
			m_empty = false;
			setText(content);
		}
	}

	Label::~Label()
	{
		delete[] m_text;
	}

	void Label::readLabel()
	{
		char text[71] = { '\0' };

		cin.getline(text, 71);

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
		}
		setText(text);
	}

	void Label::setText(const char* Cstr)
	{
		if (Cstr && !m_empty) {
			/*delete[] m_text;
			m_text = new char[strLen(Cstr) + 1];
			strCpy(m_text, Cstr);*/

			int len = strLen(Cstr);

			if (len <= 70) {
				m_text = new char[len + 1];
				strCpy(m_text, Cstr);
			}
			else {
				int diff = len - 70;
				int actual = len - diff;

				m_text = new char[actual + 1];
				strnCpy(m_text, Cstr, actual);
				m_text[actual] = '\0';
			}
		}
	}

	std::ostream& Label::printLabel() const
	{
		if (m_text && !m_empty) {

			int len = strLen(m_text) + 2;

			cout << m_frame[0];

			cout.width(len);
			cout.fill(m_frame[1]);
			cout << m_frame[1] << m_frame[2] << endl << m_frame[7];

			cout.width(len);
			cout.fill(' ');
			cout << ' ' << m_frame[3] << endl << m_frame[7] << ' ' 
				 << m_text << ' ' << m_frame[3] << endl << m_frame[7];

			cout.width(len);
			cout.fill(' ');
			cout << ' ' << m_frame[3] << endl << m_frame[6];

			cout.width(len);
			cout.fill(m_frame[5]);
			cout << m_frame[5] << m_frame[4];
		}
		return cout;
	}
}