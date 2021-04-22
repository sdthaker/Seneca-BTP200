// Workshop 5:
// Version: 1.0
// Date: 2021/02/13
// Author: Fardad Soleimanloo
// Description:
// This file tests the DIY section of workshop 5 for submission
/////////////////////////////////////////////

#include <iostream>
#include "Mark.h"
using namespace std;
using namespace sdds;
int main() {
   Mark m, n(25), k(200), p(-10);
//   const Mark m1;
   cout << "int ............" << endl;
   cout << int(m) << endl;
   // compiler has 2 options: promote to double or convert to const Mark in type conversion of compound type to primitive type. For a non const object(m in this case), it will automatically promote to double and call the double type conversion operator and if the m is const then it will run the int conversion operator. However, we are not allowed to change the main so our only option is to make all the conversion calls to operators a constant, for example: explicit operator double(); as a prototype and then you can reuturn the data member of current instance rather than creating a local variable and returning that variable.   
   cout << int(n) << endl;
   cout << int(k) << endl;
   cout << int(p) << endl;
   cout << "+= ............." << endl;
   cout << int(m += 20) << endl;
   cout << int(n += 20) << endl;
   cout << int(k += 20) << endl;
   cout << int(n += 60) << endl;
   cout << "= .............." << endl;
   cout << int(m = 80) << endl;
   cout << int(n = 120) << endl;
   cout << int(k = 70) << endl;
   cout << "double ........." << endl;
   m = 50; n = 80; k = 120;
   cout << double(m) << endl;
   cout << double(n) << endl;
   cout << double(k) << endl;
   cout << "char ..........." << endl;
   cout << char(m) << endl;
   cout << char(n) << endl;
   cout << char(k) << endl;
   cout << "int += Mark ..." << endl;
   int val = 60;
   cout << (val += n) << endl;
   cout << (val += k) << endl;
   cout << "test all values" << endl;
   p = 41;
   val = 0;
   for (int i = 0; i < 12; i++) {
      p += 5;
      val += p;
      /*cout.setf(ios::fixed);
      cout.precision(1);*/
      cout << int(p) << ": " << char(p) << ", " << double(p) << endl;
   }
   p = val / 12;
   cout << "Average: " << int(p) << " GPA: " << double(p) << endl;
   return 0;
}