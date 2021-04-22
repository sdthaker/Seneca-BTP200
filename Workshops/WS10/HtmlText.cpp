// Workshop 10
// Name: Soham Thaker
// SID: 011-748-159
// Email: sdthaker1@myseneca.ca
// Date of Completion: 2021/04/05
// The below code is my own code except for professor provided code

#include <iostream>
#include "HtmlText.h"
#include "cstring.h"

using namespace std;

namespace sdds {

	HtmlText::HtmlText(const char* filename, const char* title): Text(filename) {
		if (title) {
			delete[] m_title;
			m_title = alloc(title);
		}
	}

	HtmlText::HtmlText(const HtmlText& Ro) {
		*this = Ro;
	}

	HtmlText& HtmlText::operator=(const HtmlText& Ro) {
		if (this != &Ro) {
			(Text&)*this = Ro;
			delete[] m_title;
			if (Ro.m_title)
				m_title = alloc(Ro.m_title);
			else
				m_title = nullptr;
		}
		return *this;
	}

	HtmlText::~HtmlText() {
		delete[] m_title;
	}

	void HtmlText::write(std::ostream& os)const {
		bool MS = false;
		int i = 0;
		char value = '\0';

		os << "<html><head><title>";
		if (m_title)
			os << m_title;
		else
			os << "No Title";
		
		os << "</title></head>\n<body>\n";
		if (m_title)
			os << "<h1>" << m_title << "</h1>\n";
		
		//Text::operator[](i++)
		while ((value = (*this)[i++]) != '\0') {
			if (value == ' ') {
				if (MS)
					os << "&nbsp;";
				else {
					MS = true;
					os << ' ';
				}
			}
			else if (value == '<') {
				os << "&lt;";
				MS = false;
			}
			else if (value == '>') {
				os << "&gt;";
				MS = false;
			}
			else if (value == '\n') {
				os << "<br />\n";
				MS = false;
			}
			else {
				MS = false;
				os << value;
			}
		}
		os << "</body>\n</html>";
	}

	ostream& operator<<(ostream& os, const HtmlText& Ro) {
		Ro.write(os);
		return os;
	}

}