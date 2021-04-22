// Workshop 6 DIY
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/28
//The below code is my own code except for professor provided code

#include <iostream>
#include <fstream>
#include <iomanip>
#include "cstring.h"
#include "Stats.h"

using namespace std;

namespace sdds {

	void Stats::setEmpty() {

		delete[] m_number;
		m_number = nullptr;

		delete[] m_fileName;
		m_fileName = nullptr;

		m_totalNum = 0;
		m_columnWidth = 0;
		m_noOfColumns = 0;
		m_precision = 0;
		m_value = 0.0;
	}

	void Stats::setFilename(const char* fname, bool check) {

		if (check) {
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

	void Stats::setTotalNum() {

		ifstream fin(m_fileName);
		char ch = '\0';

		if (fin.is_open()) {

			while (fin.get(ch))
				if (ch == ',')  ++m_totalNum;
			++m_totalNum;

			if (!m_totalNum)
				setEmpty();
		}
		fin.close();
	}

	void Stats::loadNumber() {

		ifstream fin(m_fileName);
		char comma = '\0';
		double number = 0.0;
		unsigned totalNumbers = 0, i = 0;

		if (m_fileName && fin.is_open()) {

			delete[] m_number;
			m_number = new double[m_totalNum];

			while (!fin.eof()) {
				//this will return true if we try to 
				//read past the end of file

				if (totalNumbers != m_totalNum - 1)
					fin >> number >> comma;
				else
					fin >> number;

				if (fin) {
					//as long as we didnt reach the end of file or
					//as long as fin is good
					m_number[i] = number;
					++totalNumbers;
				}
				++i;
			}
		}
		m_totalNum = totalNumbers;

		fin.close();
	}

	void Stats::saveAs(const char* fileName)const {

		ifstream fin(m_fileName);
		ofstream fout(fileName);
		
		char ch = '\0';

		if (fout.is_open())
			while (fin.get(ch)) 
				fout << ch;

		fin.close();
		fout.close();
	}

	void Stats::setState(const Stats& other, const char* fileName, 
		unsigned columnWidth, unsigned noOfColumns, unsigned precision, 
		bool flag, bool check)
	{
		m_columnWidth = columnWidth;
		m_noOfColumns = noOfColumns;
		m_precision = precision;

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

			setTotalNum();
			loadNumber();
		}
	}

	Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision)
	{
		setState(*this, nullptr, columnWidth, noOfColumns, precision);
	}

	Stats::Stats(const char* filename, unsigned columnWidth,
				unsigned noOfColumns, unsigned precision)
	{
		setState(*this, filename, columnWidth, noOfColumns, precision, true);
	}

	Stats::Stats(const Stats& other) {
		if (other)
			setState(other, other.m_fileName, other.m_columnWidth, 
				     other.m_noOfColumns,other.m_precision, true, true);
	}

	Stats::~Stats() {
		delete[] m_fileName;
		delete[] m_number;
	}

	Stats& Stats::operator=(const Stats& other) {

		if (this != &other && *this && other) {
			m_totalNum = 0;
			delete[] m_number;
			m_number = nullptr;

			setState(other, nullptr, other.m_columnWidth, other.m_noOfColumns,
					other.m_precision, true);
		}
		return *this;
	}

	double& Stats::operator[](unsigned idx) {
		if (*this) {
			if (idx + 1 > m_totalNum)
				return m_number[idx - m_totalNum];
			else
				return m_number[idx];
		}
		else
			return m_value;
	}

	double Stats::operator[](unsigned idx) const {
		Stats temp = *this;
		return temp[idx];
	}

	Stats::operator bool() const {
		return m_totalNum;
	}

	void Stats::sort(bool ascending) {
		if (ascending && *this) {
			double temp = 0.0;
			for (unsigned i = m_totalNum - 1; i > 0; i--) {
				for (unsigned j = 0; j < i; j++) {
					if (m_number[j] > m_number[j + 1]) {
						temp = m_number[j];
						m_number[j] = m_number[j + 1];
						m_number[j + 1] = temp;
					}
				}
			}
		}
		else {
			if (*this) {
				double temp = 0.0;
				for (unsigned i = m_totalNum - 1; i > 0; i--) {
					for (unsigned j = 0; j < i; j++) {
						if (m_number[j] < m_number[j + 1]) {
							temp = m_number[j];
							m_number[j] = m_number[j + 1];
							m_number[j + 1] = temp;
						}
					}
				}
			}
		}
	}

	unsigned Stats::size()const {
		return m_totalNum;
	}

	const char* Stats::name()const {
		return m_fileName;
	}

	ostream& Stats::display(double* arr, unsigned totalNumbers,
							ostream& ostr) const
	{
		unsigned j = 0;
		bool check = true;

		if (!arr) arr = m_number;

		for (unsigned i = 0; i < totalNumbers; i++) {
			ostr.width(m_columnWidth);
			ostr.fill(' ');
			ostr.setf(ios::fixed);
			ostr.precision(m_precision);
			ostr << arr[i];

			++j;
			if (m_noOfColumns == j) {
				ostr << endl;
				j = 0;
				if (i == totalNumbers - 1)
					check = false;
			}
			if (i == totalNumbers - 1 && check)
				ostr << endl;
		}
		return ostr;
	}

	unsigned Stats::occurrence(double min, double max, ostream& ostr)
	{
		double* arr = nullptr, * temp = nullptr;
		unsigned count = 0;

		if (*this) {
			ostr << endl;
			for (unsigned i = 0; i < m_totalNum; i++) {
				if (m_number[i] > min && m_number[i] < max) {

					temp = new double[count + 1];
					for (unsigned i = 0; i < count; i++) temp[i] = arr[i];
					temp[count] = m_number[i];

					delete[] arr;
					arr = temp;

					++count;
				}
			}
			display(arr, count, ostr);
			cout << "Total of " << count << " numbers are between "
				 << min << " and " << max << endl;
		}
		delete[] arr;
		return count;
	}

	ostream& Stats::view(ostream& ostr) const {

		if (*this) {
			ostr << m_fileName << endl;
			ostr.width(strLen(m_fileName));
			ostr.fill('=');
			ostr << "=" << endl << endl;

			display(nullptr, m_totalNum, ostr);
			ostr << "Total of " << m_totalNum << " listed!" << endl;
		}
		return ostr;
	}

	istream& Stats::getFile(istream& istr) {

		char buf[10] = { '\0' };
		char* og = nullptr, * tmp = nullptr;
		int size = 0;
		bool flag = true;
		Stats temp;

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
		setState(temp, og, m_columnWidth, m_noOfColumns, m_precision, true);

		delete[] og;
		return istr;
	}

	ostream& operator<<(ostream& os, const Stats& stats) {
		stats.view(os);
		return os;
	}

	istream& operator>>(istream& is, Stats& stats) {
		stats.getFile(is);
		return is;
	}
}