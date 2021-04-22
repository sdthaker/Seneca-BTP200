// Workshop 2 Lab
// Name: Soham Thaker
// SID: 011-748-159
// Email: sdthaker1@myseneca.ca
// Date of Completion: 2021/01/24
//The below code is my own code and I have not taken any help in order to complete this workshop.

#include <iostream>
#include "cstring.h"
#include "Employee.h"
#include "File.h"

using namespace std;

namespace sdds {

   int noOfEmployees;
   Employee* employees;

   void sort() {
      int i, j;
      Employee temp;

      for (i = noOfEmployees - 1; i > 0; i--) {

         for (j = 0; j < i; j++) {

            if (employees[j].m_empNo > employees[j + 1].m_empNo) {

               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   bool load(Employee& emp) {
       bool ok = false;
       char name[128];
        
       if (read(emp.m_empNo) && read(emp.m_salary) && read(name)) {

           emp.m_name = new char[strLen(name) + 1];
           strCpy(emp.m_name, name);

           ok = true;
       }
      return ok;
   }
 
   bool load() {

      bool ok = false;
      int i = 0;

      if (openFile(DATAFILE)) {

          noOfEmployees = noOfRecords();
          employees = new Employee[noOfEmployees];
          int read = 0;
        
          for (i = 0; i < noOfEmployees; i++) {

              if (load(employees[i]))
                  read += 1;
          }

          if (read == noOfEmployees)
              ok = true;
          else
              cout << "Error: incorrect number of records read"
                      " the data is possibly corrupted";
       
          closeFile();
      }
      else
         cout << "Could not open data file: " << DATAFILE << endl;

      return ok;
   }

   void display(const Employee& emp) {

       cout << emp.m_empNo << ": " << emp.m_name 
            << ", " << emp.m_salary << endl;
   }

   void display() {

       cout << "Employee Salary report, sorted by employee number" 
            << endl << "no- Empno, Name, Salary" 
            << endl << "------------------------------------------------" << endl;

       sort();
     
       for (int i = 0; i < noOfEmployees; i++) {
           cout << i + 1 << "- ";
           display(employees[i]);
       }
   }

   void deallocateMemory() {

       for (int i = 0; i < noOfEmployees; i++) {
           delete[] employees[i].m_name;
           employees[i].m_name = nullptr;
       }
       delete[] employees;
       employees = nullptr;
   }
}