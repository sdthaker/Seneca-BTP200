// Workshop 2 Lab
// Name: Soham Thaker
// SID: 011-748-159
// Email: sdthaker1@myseneca.ca
// Date of Completion: 2021/01/24
//The below code is my own code and I have not taken any help in order to complete this workshop.

#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#define DATAFILE "employees.csv"

namespace sdds {
    struct Employee {
        char* m_name;
        int m_empNo;
        double m_salary;
    };

    void sort();
    bool load(Employee& emp);
    bool load();
    void display(const Employee& emp);
    void display();
    void deallocateMemory();
}
#endif // SDDS_EMPLOYEE_H_