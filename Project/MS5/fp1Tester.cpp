// Final Project Tester
// file: fp1Tester.cpp
// Version: 0.9
// Date: 2021-03-26
// Author: Fardad 
// Description:
// This file tests the Final project 
// with no data file
/////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "PreTriage.h"
#include "utils.h"
using namespace sdds;
int main() {
   sdds::debug = true;
   std::ofstream("data.csv").close();
   PreTriage P("data.csv");
   P.run();
   return 0;
}

