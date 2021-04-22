// Workshop 4 Lab
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/07
//The below code is my own code and I have not taken any help in order to complete this workshop.

#ifndef SDDS_CANISTER_H
#define SDDS_CANISTER_H
#include <iostream>

namespace sdds {
   class Canister {
      char* m_contentName = nullptr;
      double m_diameter = 0.0;
      double m_hieght = 0.0;
      double m_contentVolume = 0.0;
      bool m_usable = true;  
      void setToDefault();
      void setName(const char* Cstr);
      bool isEmpty()const;  
      bool hasSameContent(const Canister& C)const; 
   public:
      Canister();
      Canister(const char* contentName);
      Canister(double hieght, double diameter,
         const char* contentName = nullptr);
      ~Canister();
      Canister& setContent(const char* contentName);
      Canister& pour(double quantity);
      Canister& pour(Canister& C);
      double volume()const;
      std::ostream& display()const;
      double capacity()const;
      void clear();
   };
}

#endif 
