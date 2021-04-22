#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>

#include "Student.h"

template <typename T, char ob>
class Util {
	T** m_student = nullptr;
	int m_studentNum = 0;
public:
	Util() {}
	Util(const Util<T, ob>& other);
	bool operator==(const Util<T, ob>& other);
	std::istream& read(std::istream& is);
	std::ostream& write(std::ostream& os) const;
	Util& operator=(const Util& other);
	~Util();
};

template <typename T, char ob>
bool Util<T, ob>::operator==(const Util<T, ob>& other) {
	bool flag = false;
	for (int i = 0; i < m_studentNum; i++)
		flag = (*(m_student[i]) == *(other.m_student[i]));
	return flag;
}

//template <typename T>
//Util<T>::Util() {
//}

template <typename T, char ob>
Util<T, ob>::Util(const Util<T, ob>& other) {
	*this = other;
}

template <typename T, char ob>
Util<T, ob>& Util<T, ob>::operator=(const Util<T, ob>& other) {
	if (this != &other) {
		m_studentNum = other.m_studentNum;

		for (int i = 0; i < m_studentNum; i++)
			delete m_student[i];
		//delete[] m_student;*/
		//delete[] m_student;

		if (ob == 'S') {
			//m_student = new Student[m_studentNum];
			m_student = new College * [m_studentNum];
			for (int i = 0; i < m_studentNum; i++) {
				m_student[i] = new Student;
				m_student[i]->assignSet(*(other.m_student[i]));
			}
		}
	}
	return *this;
}

template <typename T, char ob>
Util<T, ob>::~Util() {
	for (int i = 0; i < m_studentNum; i++)
		delete m_student[i];
	//delete[] m_student;
}

template <typename T, char ob>
std::istream& Util<T, ob>::read(std::istream& is) {
	
	std::cout << "\nHow many Students: ";
	is >> m_studentNum;

	for (int i = 0; i < m_studentNum; i++)
		delete m_student[i];

	if (ob == 'S') {
		//m_student = new Student[m_studentNum];
		m_student = new College * [m_studentNum];
		for (int i = 0; i < m_studentNum; i++) {
			m_student[i] = new Student;
			is >> *(m_student[i]);
		}
	}
	return is;
}

template <typename T, char ob>
std::ostream& Util<T, ob>::write(std::ostream& os) const {
	os << "\nDisplay:\n";
	for (int i = 0; i < m_studentNum; i++)
		i > 0 ? os << std::endl << *(m_student[i]) : os << *(m_student[i]);
	return os;
}

template <typename T, char ob>
std::istream& operator>>(std::istream& is, Util<T, ob>& other) {
	return other.read(is);
}

template <typename T, char ob>
std::ostream& operator<<(std::ostream& is, const Util<T, ob>& other) {
	return other.write(is);
}

#endif