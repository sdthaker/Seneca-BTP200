// Workshop 10
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/04/05
//The below code is my not own code and I have used professor's logic for strStr and strCat function

#ifndef SDDS_CSTRING_H
#define SDDS_CSTRING_H

namespace sdds {

	void strCpy(char* des, const char* src);
	void strnCpy(char* des, const char* src, int len);
	int strCmp(const char* s1, const char* s2);
	int strnCmp(const char* s1, const char* s2, int len);
	int strLen(const char* s);
	const char* strStr(const char* str1, const char* str2);
	void strCat(char* des, const char* src);
}

#endif