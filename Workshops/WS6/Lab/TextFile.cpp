// Workshop 6 Lab
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/21
//The below code is my own code except for professor provided code

#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"

using namespace std;

namespace sdds {

	Line::operator const char* () const {
		return (const char*)m_value;
	}

	Line& Line::operator=(const char* lineValue) {
		delete[] m_value;
		m_value = new char[strLen(lineValue) + 1];
		strCpy(m_value, lineValue);
		return *this;
	}

	Line::~Line() {
		delete[] m_value;
	}

	void TextFile::setEmpty() {

		delete[] m_textLines;
		m_textLines = nullptr;

		delete[] m_fileName;
		m_fileName = nullptr;

		m_noOfLines = 0;
	}

	void TextFile::setFilename(const char* fname, bool isCopy) {

		if (isCopy) {
			const char prefix[] = "C_";
			delete[] m_fileName;
			m_fileName = new char[strLen(fname) + 3];
			strCpy(m_fileName, prefix);
			strCat(m_fileName, fname);
		}
		else {
			delete[] m_fileName;
			m_fileName = new char[strLen(fname) + 1];
			strCpy(m_fileName, fname);
		}
	}

	void TextFile::setNoOfLines() {

		ifstream fin(m_fileName);
		char ch = '\0';
		//string str;
		//while (getline(fin, str))
		//increment m_noOfLines

		if (fin.is_open()) {

			while (fin.get(ch))
				if (ch == '\n')  ++m_noOfLines;
			++m_noOfLines;

			if (!m_noOfLines)
				setEmpty();
		}
		fin.close();
	}

	void TextFile::loadText() {

		ifstream fin(m_fileName);
		string str = { '\0' };
		int noOfLines = 0;

		if (m_fileName && fin.is_open()) {
			delete[] m_textLines;
			m_textLines = new Line[m_noOfLines];

			for (int i = 0; getline(fin, str); i++) {
				if (fin) {
					m_textLines[i] = str.c_str();
					++noOfLines;
				}
			}
			m_noOfLines = noOfLines;
		}
		fin.close();
	}

	void TextFile::saveAs(const char* fileName)const {

		ofstream fout(fileName);

		if (fout.is_open())
			for (unsigned i = 0; i < m_noOfLines; i++)
				fout << m_textLines[i].m_value << endl;

		fout.close();
	}

	TextFile::TextFile(unsigned pageSize) {

		m_pageSize = pageSize;
		setEmpty();
	}

	void TextFile::setState(const TextFile& other, const char* fileName,
		bool flag, bool check) {

		if (flag) {
			if (fileName && check)
				setFilename(other.m_fileName, true);
			else {
				if (fileName)
					setFilename(fileName);
				else if (!m_fileName)
					setFilename(other.m_fileName);
			}

			if (other)
				other.saveAs(m_fileName);

			setNoOfLines();
			loadText();
		}
	}

	TextFile::TextFile(const char* filename, unsigned pageSize) {
		setState(*this, filename, true);
	}

	TextFile::TextFile(const TextFile& other) {
		if (other) {
			m_pageSize = other.m_pageSize;
			setState(other, other.m_fileName, true, true);
		}
	}

	TextFile& TextFile::operator=(const TextFile& other) {

		if (this != &other && *this && other) {
			m_noOfLines = 0;
			delete[] m_textLines;
			m_textLines = nullptr;

			setState(other, nullptr, true);
		}
		return *this;
	}

	TextFile::~TextFile() {
		delete[] m_fileName;
		delete[] m_textLines;
	}

	unsigned TextFile::lines() const {
		return m_noOfLines;
	}

	ostream& TextFile::view(ostream& ostr) const {

		unsigned counter = 0;

		if (*this) {
			ostr << m_fileName << endl;
			ostr.width(strLen(m_fileName));
			ostr.fill('=');
			ostr << "=" << endl;

			for (unsigned i = 0; i < m_noOfLines; i++) {

				++counter;
				ostr << m_textLines[i].m_value << endl;
				if (m_pageSize == counter) {
					ostr << "Hit ENTER to continue...";
					cin.get();
					counter = 0;
				}
			}
		}
		return ostr;
	}

	istream& TextFile::getFile(istream& istr) {

		char buf[10] = { '\0' };
		char* og = nullptr, * tmp = nullptr;
		int size = 0;
		bool flag = true;
		TextFile temp;

		while (flag) {

			istr.get(buf, 10, '\n');

			if (istr) {
				int bufLen = strLen(buf);

				tmp = new char[size + bufLen + 1];

				strnCpy(tmp, og, size);
				strnCpy(&tmp[size], buf, bufLen);

				tmp[bufLen + size] = '\0';

				delete[] og;
				og = tmp;
				tmp = nullptr;
				size += bufLen;

				if (bufLen < 9) {
					flag = false;
					istr.clear();
					istr.ignore();
				}
			}
		}
		setState(temp, og, true);

		delete[] og;
		return istr;
		/*char arr[10000] = { '\0' };
		istr.getline(arr, 10000, '\n');

		istr.ignore();
		//setState(temp, arr, true);
		*/

		/*string str;
		getline(istr, str);
		setFilename(str.c_str());*/
	}

	const char* TextFile::operator[](unsigned index) const {

		if (*this) {
			if (index + 1 > m_noOfLines)
				return m_textLines[index - m_noOfLines].m_value;
			else
				return m_textLines[index].m_value;
		}
		else {
			return nullptr;
		}
	}

	TextFile::operator bool() const {
		return m_noOfLines;
	}

	const char* TextFile::name() const {
		return m_fileName;
	}

	std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
		text.view(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, TextFile& text)
	{
		text.getFile(istr);
		return istr;
	}
}