// Workshop 9:
// Version: 1.0
// Date: 2021-02-26
// Author: Fardad Soleimanloo
// Description:
// This file tests the lab section of your workshop
// Modify the main function as stated in the workshop description
// and the comments stated in the main function
// Workshop 9
// Name: Soham Thaker
// SID: 011-748-159
// Email: sdthaker1@myseneca.ca
// Date of Completion: 2021/03/29
// The below code is my own code except for professor provided code
/////////////////////////////////////////////
#include <iostream>
#include "Car.h"
#include "Employee.h"
#include "ReadWrite.h"
#include "Student.h"
#include "Collection.h"
#include "searchNlist.h"
using namespace std;
using namespace sdds;

int main() {
   Car C[8] = { Car("GVFGHI", "Tesla Model S"), Car("ABCDEF", "BMW 320"), Car("CDEFGH", "Ford Festiva"), 
                Car("BCDEFG", "Ford Festiva"),Car("GVDGHI", "Tesla Model 3"), Car("EFGHIJ", "Nissan Maxima"), 
                Car("GVDEFG", "Tesla Model X") };
   Student S[6] = { Student(23456, "Lisa Simpson",4.0),Student(45678, "Ralph Wiggum",2.1), Student(56789, "Milhouse Van Houten",4.0), 
                Student(67890, "Todd Flanders", 3.5), Student(34567, "Nelson Muntz",3.0),Student(12345, "Bart Simpson",1.5) };
   Employee E[6] = { Employee(213456, "Carl Carlson", 62344.56,111), Employee(122345, "Mindy Simmons", 65432.44,222), 
                Employee(435678, "Lenny Leonard", 43213.22,111), Employee(546789, "Waylon Smithers", 654321.55,333), 
                Employee(657890, "Frank Grimes", 34567.88,333), Employee(364567, "Homer Simpson", 55432.11,111) };

   Collection<Car> Cres;
   Collection<Student> Sres;
   Collection<Employee>Eres;


   listArrayElements<Car>("All the cars:", C, 7);        
   cout << "Searching for Tesla cars: " << endl;

   /*
   Modified the below function call to search function to pass
   2 template paramters, a custom type and a primitive type. 
   These template parameters identify the types of 1st, 
   2nd and 3rd function arguments. The function itself takes 4 arguments: 
   1. Collection class templetes' local object created in this scope 
      named as 'Cres',
   2. an array of local object of custom type created in this scope, 
      from where we are to search for a const string passed as the 
      4th parameter,
   3. size of the 3rd argument, 
   4. the string to search from the 2nd argument's data member, m_makeModel
   There is no need to pass the template parameters in the below case
   because compiler at the time of compilation can interpret
   the template types of the arguments
   */
   if (search<Car, const char*>(Cres, C, 7, "Tesla")) { 
      cout << Cres.size() << " match" << (Cres.size() == 1 ? "" : "es") << " found:" << endl;
      for (int i = 0; i < Cres.size(); i++) {
         cout << (i + 1) << ": " << Cres[i] << endl;
      }   /*
   Modified the below function call to listArrayElements to pass
   a templete paramter of Car custom type and passed 3 function arguments:
   1. title to print the title on the screen,
   2. C which is an array of Car objects(internally this
      functions loops and prints all the objects' data members)
   3. total size of the C array
   There is no need to pass the template parameters in the below case
   because compiler at the time of compilation can interpret
   the template types of the arguments
   */
   }
   else {
      cout << "No matches found!" << endl;
   }
   cout << endl;

   /*
   Modified the below function call to listArrayElements 
   to pass a templete paramter of Student custom type and 
   passed 3 function arguments: 
   1. title to print the title on the screen, 
   2. S which is an array of Student objects(internally this 
      functions loops and prints all the objects' data members) 
   3. total size of the S array
   There is no need to pass the template parameters in the below case
   because compiler at the time of compilation can interpret
   the template types of the arguments
   */
   listArrayElements<Student>("All students:", S, 6);
   cout << "Searching for students with 4.0 Gpa:" << endl;

   /*
   Modified the below function call to search function 
   to pass 2 template paramters, a custom type and a primitive type. 
   These template parameters identify the types of 1st,
   2nd and 3rd function arguments. The function itself takes 4 arguments:
   1. Collection class templetes' local object created in this 
      scope named as 'Sres',
   2. an array of local object of custom type created in this scope,
      from where we are to search for a const string passed as
      the 4th parameter,
   3. size of the 3rd argument,
   4. the string to search from the 2nd argument's data member, m_gpa
   There is no need to pass the template parameters in the below case
   because compiler at the time of compilation can interpret
   the template types of the arguments
   */
   if (search<Student, double>(Sres, S, 6, 4.0)) {
      cout << Sres.size() << " match" << (Sres.size() == 1 ? "" : "es") << " found:" << endl;
      for (int i = 0; i < Sres.size(); i++) {
         cout << (i + 1) << ": " << Sres[i] << endl;
      }
   }
   else {
      cout << "No matches found!" << endl;
   }
   cout << endl;

   /*
   Modified the below function call to listArrayElements to
   pass a templete paramter
   of Employee custom type and passed 3 function arguments:
   1. title to print the title on the screen,
   2. E which is an array of Employee objects(internally this
      functions loops and prints all the objects' data members)
   3. total size of the E array
   There is no need to pass the template parameters in the below case
   because compiler at the time of compilation can interpret
   the template types of the arguments
   */
   listArrayElements<Employee>("All employees:", E, 6);

   cout << "Searching for employees who share office number 111:" << endl;

   /*
   Modified the below function call to search function 
   to pass 2 template paramters, a custom type and a primitive type. 
   These template parameters identify the types of 1st,
   2nd and 3rd function arguments. The function itself takes 4 arguments:
   1. Collection class templetes' local object created in this scope 
      named as 'Eres',
   2. an array of local object of custom type created in this scope,
      from where we are to search for a const string passed as the 
      4th parameter,
   3. size of the 3rd argument,
   4. the string to search from the 2nd argument's data member, m_office
   There is no need to pass the template parameters in the below case
   because compiler at the time of compilation can interpret
   the template types of the arguments
   */
   if (search<Employee, int>(Eres, E, 6, 111)) { 
      cout << Eres.size() << " match" << (Eres.size() == 1 ? "" : "es") << " found:" << endl;
      for (int i = 0; i < Eres.size(); i++) {
         cout << (i + 1) << ": " << Eres[i] << endl;
      }
   }
   else {
      cout << "No matches found!" << endl;
   }
   cout << endl;

   cout << "Searching for employees who share office number 555:" << endl;

   /*
   Modified the below function call to search function 
   to pass 2 template paramters, a custom type and a primitive type.
   These template parameters identify the types of 1st,
   2nd and 3rd function arguments. The function itself 
   takes 4 arguments:
   1. Collection class templetes' local object created in 
      this scope named as 'Eres',
   2. an array of local object of custom type created in this scope,
   from where we are to search for a const string passed as the 4th parameter,
   3. size of the 3rd argument,
   4. the string to search from the 2nd argument's data member, m_office
   There is no need to pass the template parameters in the below case
   because compiler at the time of compilation can interpret
   the template types of the arguments
   */
   if (search<Employee, int>(Eres, E, 6, 555)) {        
      cout << Eres.size() << " match" << (Eres.size() == 1 ? "" : "es") << " found:" << endl;
      for (int i = 0; i < Eres.size(); i++) {
         cout << (i + 1) << ": " << Eres[i] << endl;
      }
   }
   else {
      cout << "No matches found!" << endl;
   }
   cout << endl;

   int a[]{ 10,20,30,40,50,60 };

   /*
   Modified the below function call to listArrayElements 
   to pass 3 function arguments:
   1. title to print the title on the screen,
   2. E which is an array of Employee objects(internally this
      functions loops and prints all the objects' data members)
   3. total size of the E array
   There is no need to pass the template parameters in the below case
   because compiler at the time of compilation can interpret
   the template types of the arguments
   */
   listArrayElements<int>("INTEGERS", a, 6);
   return 0;
}