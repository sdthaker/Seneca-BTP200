// Workshop 1 DIY
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/01/18

#include <iostream>
#include <cstring>
#include "cstring.h"

using namespace sdds;
using namespace std;

int main() {

	char str1[80] = "abcdefghijklmnopqrstuvwxyz";
	char str2[80];
	const char* fadd;
	strCpy(str2, str1);
	cout << str2 << endl;
	strnCpy(str2, "@@@", 2);
	cout << str2 << endl;
	strnCpy(str2, "@@@", 3);
	cout << str2 << endl;
	strnCpy(str2, "@@@", 4);
	cout << str2 << endl;
	cout << strCmp("aab", "aaa") << endl;
	cout << strnCmp("aab", "aaa", 2) << endl;
	cout << strnCmp("aab", "aaa", 3) << endl;
	cout << strLen("") << endl;
	cout << strLen(str1) << endl;
	fadd = strStr(str1, "jkl");
	cout << fadd << endl;
	fadd = strstr(str1, "bbb");
	if (!fadd) cout << "not found" << endl;
	strCpy(str2, "john ");
	strCat(str2, "doe");
	cout << str2 << endl;
	return 0;
}