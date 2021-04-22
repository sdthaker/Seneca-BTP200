#ifndef COLLEGE_H
#define COLLEGE_H

#include <iostream>

class College {
public:
	College() {}
	virtual bool operator==(const College& other) = 0;
	virtual void assignSet(const College& other) = 0;
	virtual std::istream& read(std::istream& is) = 0;
	virtual std::ostream& write(std::ostream& os) const = 0;
	virtual ~College(){}
	virtual char type() const = 0;
};

std::istream& operator>>(std::istream& is, College& other);
std::ostream& operator<<(std::ostream& os, const College& other);


#endif // !COLLEGE_H