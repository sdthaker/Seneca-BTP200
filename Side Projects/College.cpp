#include <iostream>
#include "College.h"

using namespace std;

//bool College::operator==(const Student& other) {
//	return *this == other;
//}

istream& operator>>(std::istream& is, College& other) {
	return other.read(is);
}

std::ostream& operator<<(std::ostream& os, const College& other) {
	return other.write(os);
}