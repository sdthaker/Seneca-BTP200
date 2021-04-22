/* Citation and Sources...
Final Project Milestone 1
Module: Utils
Filename: utils.cpp
Author	Soham Thaker
Revision History
-----------------------------------------------------------
Date        Reason
2021/03/13  Preliminary release
2021/03/24  1. Updated Cstr function with else block to set the stream to good once it
			goes bad and to exit the loop rather than to loop endlessly
			2. Updated both the getInt to localize the logic.
2021/04/08	Updated the dates for revision history, since all the files had year as 2020
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;

namespace sdds {
	bool debug = false;  // made global in utils.h

	int getTime() {  
	   int mins = -1;
	   if (debug) {
	      Time t(0);
	      cout << "Enter current time: ";
	      do {
	         cin.clear();
	         cin >> t;  
	         if (!cin) {
	            cout << "Invlid time, try agian (HH:MM): ";
	            cin.clear();
	         }
	         else {
	            mins = int(t);
	         }
	         cin.ignore(1000, '\n');
	      } while (mins < 0);
	   }
	   else {
	      time_t t = time(NULL);
	      tm lt = *localtime(&t);
	      mins = lt.tm_hour * 60 + lt.tm_min;
	   }
	   return mins;
	}

	int getInt(const char* prompt) {

		int value = 0;
		bool flag = true;
		char nextChar = '\0';

		if (prompt) {
			cout << prompt;
		}
		while (flag) {

			cin >> value;

			if (cin.fail()) {
				cout << "Bad integer value, try again: ";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else {
				cin.get(nextChar);
				if (nextChar != '\n') {
					cout << "Enter only an integer, try again: ";
					cin.clear();
					cin.ignore(10000, '\n');
				}
				else
					flag = false;
			}
		}
		return value;
	}

	int getInt(int min, int max, const char* prompt,
		const char* errorMessage, bool showRangeAtError) {

		int value = 0;
		bool check = true;

		if (prompt)
			cout << prompt;

		while (check) {
			value = getInt(nullptr);

			if (value < min || value > max) {
				if (errorMessage && showRangeAtError)
					cout << errorMessage << "[" << min << " <= value <= " << max << "]: ";
				else if (errorMessage)
					cout << errorMessage;
			}
			else
				check = false;
		}
		return value;
	}

	char* getcstr(const char* prompt, istream& istr, char delimiter) {

		char buf[50] = { '\0' };
		char* og = nullptr, *tmp = nullptr;
		int size = 0;
		bool flag = true;

		if (prompt) {
			cout << prompt;
		}
		while (flag) {

			istr.get(buf, 50, delimiter);

			if (istr) {
				int bufLen = strlen(buf);

				tmp = new char[size + bufLen + 1];

				if (og)
					strncpy(tmp, og, size);
				strncpy(&tmp[size], buf, bufLen);

				tmp[bufLen + size] = '\0';

				delete[] og;
				og = tmp;
				tmp = nullptr;
				size += bufLen;

				if (bufLen < 49) {
					flag = false;
					istr.clear();
					istr.ignore();
				}
			}
			else {
				istr.clear();
				flag = false;
			}
		}
		return og;
	}
}