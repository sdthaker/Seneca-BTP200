// Workshop 2 Lab
// Name: Soham Thaker
// SID: 011-748-159
// Email: sdthaker1@myseneca.ca
// Date of Completion: 2021/01/24
//The below code is my own code and I have not taken any help in order to complete this workshop.

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {

   FILE* fptr;

   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }

   void closeFile() {
      if (fptr) fclose(fptr);
   }

   bool read(char* name) {

       bool flag = fscanf(fptr, "%[^\n]\n", name);
       return flag;
   }

   bool read(int& empNo) {

       bool flag = fscanf(fptr, "%d,", &empNo);
       return flag;
   }

   bool read(double& salary) {
       
       bool flag = fscanf(fptr, "%lf,", &salary);
       return flag;
   }
   
}