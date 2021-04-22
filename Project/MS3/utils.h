/* Citation and Sources...
Final Project Milestone 3
Module: Utils
Filename: utils.h
Author	Soham Thaker
Revision History
-----------------------------------------------------------
Date        Reason
2020/03/13  Preliminary release
2021/04/08	Updated the dates for revision history, since all the files had year as 2020
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>

namespace sdds {
   extern bool debug; 
   int getInt(const char* prompt = nullptr);
   int getInt(int min, int max, const char* prompt = nullptr, 
                const char* errorMessage = nullptr, bool showRangeAtError = true);
   char* getcstr(const char* prompt = nullptr, 
       std::istream& istr = std::cin, char delimiter = '\n');
   int getTime(); 
}
#endif // !SDDS_UTILS_H_

