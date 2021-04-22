#include <iostream>
#include "Util.h"
#include "College.h"

using namespace std;

int main() {

	//ask user if they want to create a student or faculty
	//faculty will br exact same thing just like Student
	//ask the user here what do they want to create...

	int clg = 0;
	cout << "How many college: ";
	cin >> clg;
	Util<College, 'S'>* s = new Util<College, 'S'>[clg];

	for (int i = 0; i < clg; i++) {
		std::cout << "\nCollege No: " << i + 1;
		cin >> s[i];
	}

	for (int i = 0; i < clg; i++)
		cout << s[i];

	//testing copy operations and operator= for 2 identical students 
	//uncomment to test it, make sure to create at least 2 students 
	s[0] = s[1];
	if (s[0] == s[1])
		cout << "same";

	delete[] s;
}