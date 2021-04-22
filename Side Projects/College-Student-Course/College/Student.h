#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include "College.h"
#include "Course.h"

class Student: public College {
	std::string m_studentName = "";
	int m_courseNum = 0;
	Course* m_course = nullptr;
public:
 	Student() {}
	Student(const Student& other);
	Student& operator=(const Student& other);
	bool operator==(const College& other) override;
	void assignSet(const College& other) override;
	std::istream& read(std::istream& is) override;
	std::ostream& write(std::ostream& os) const override;
	char type() const override;
	~Student();
};

//std::istream& operator>>(std::istream& is, Course& other);
//std::ostream& operator<<(std::ostream& os, const Course& other);

#endif