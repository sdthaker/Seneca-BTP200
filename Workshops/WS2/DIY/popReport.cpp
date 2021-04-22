// Workshop 2 DIY
// Name: Soham Thaker
// SID: 011-748-159
// Email: sdthaker1@myseneca.ca
// Date of Completion: 2021/01/24
//The below code is my own code and I have not taken any help in order to complete this workshop.

#include "Population.h"
using namespace sdds;

int main() {

   if (load("PCpopulations.csv")) {
      display();
   }
   deallocateMemory();
   return 0;
}