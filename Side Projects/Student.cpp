#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(const Student& other) {
	*this = other;
}

void Student::assignSet(const College& other){
	const Student *s = dynamic_cast<const Student*>(&other);
	if (s) {
		*this = *s;
	}
	else {
		std::cout << "Coversion is not possible. Types dont match";
	}
}

Student& Student::operator=(const Student& other) {
	if (this != &other) {
		delete[] m_course;

		m_studentName = other.m_studentName;
		m_courseNum = other.m_courseNum;

		m_course = new Course[m_courseNum];
		for(int i = 0; i < m_courseNum; i++)
			m_course[i] = other.m_course[i];
	}
	return *this;
}

Student::~Student() {
	delete[] m_course;
}

bool Student::operator==(const College& other) {
	bool flag = false;

	const Student* s = dynamic_cast<const Student*>(&other);
	if (s) {
		for (int i = 0; i < m_courseNum; i++)
			flag = m_course[i] == s->m_course[i];
	}
	else
		std::cout << "Coversion is not possible. Types dont match";

	return flag;
}

istream& Student::read(istream& is) {
	
	cout << "\nHow many courses: ";
	is >> m_courseNum;

	cout << "Student Name: ";
	is >> m_studentName;
	
	delete[] m_course;
	m_course = new Course[m_courseNum];

	for (int i = 0; i < m_courseNum; i++) {
		cout << "Course name of " << i+1 << ": ";
		m_course[i].read(is);
	}

	return is;
}

ostream& Student::write(ostream& os) const {
	os << m_studentName << endl;
	for (int i = 0; i < m_courseNum; i++)
		m_course[i].write(os);
	return os;
}

char Student::type() const {
	return 'S';
}

