// Workshop 5 Lab
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/14
//The below code is my own code and I have not taken any help in order to complete this workshop.

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator int() const;
      operator bool() const;
      operator double() const;
      bool operator ~() const;
      Account& operator=(const int acc);
      Account& operator=(Account& Ro);
      Account& operator+=(double val);
      Account& operator-=(double val);
      Account& operator<<(Account& Ro);
      Account& operator>>(Account& Ro);
   };
   double operator+=(double& val, const Account& Ro);
   double operator+(const Account& Lo, const Account& Ro);
}
#endif // SDDS_ACCOUNT_H_
