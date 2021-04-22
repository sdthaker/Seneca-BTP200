// Workshop 5 Lab
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/14
//The below code is my own code and I have not taken any help in order to complete this workshop except the professor provided code.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;

namespace sdds {
   void Account::setEmpty() {
      m_number = -1;    
      m_balance = 0.0;
   }

   Account::Account() {  
      m_number = 0; 
      m_balance = 0.0;
   }

   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999    
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }

   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool() const {
       return (m_number >= 10000 && m_number <= 99999) &&
               m_balance >= 0 ? true : false;
   }

   Account::operator int() const {
       return m_number;
   }

   Account::operator double() const {
       return m_balance;
   }

   bool Account::operator~() const {
       return m_number == 0;
   }

   Account& Account::operator=(const int acc) {
       if (~*this) { 
            if (acc >= 10000 && acc <= 99999)
                m_number = acc;
            else
                setEmpty();
       }
       return *this;
   }

   Account& Account::operator=(Account& Ro) {
       if (~*this && Ro) {
           m_number = Ro.m_number;
           m_balance = Ro.m_balance;

           Ro.m_number = 0;
           Ro.m_balance = 0;
       }
       return *this;
   }

   Account& Account::operator+=(double val) {
       if (*this && val > 0)
           m_balance += val;
       return *this;
   }

   Account& Account::operator-=(double val) {
       if (*this && val > 0 && (m_balance - val) > 0)
           m_balance -= val;
       return *this;
   }

   Account& Account::operator<<(Account& Ro) {
       if (this != &Ro && Ro && *this) {
           m_balance += Ro.m_balance;
           Ro.m_balance = 0;
       }
       return *this;
   }

   Account& Account::operator>>(Account& Ro) {
       Ro << *this;
       return *this;
   }

   double operator+(const Account& Lo, const Account& Ro) {

       double balance = 0.0;
       if(Lo && Ro)
            balance = (double)Lo + (double)Ro;
       return balance;
   }

   double operator+=(double& val, const Account& Ro) {
       return val += (double)Ro;
   }
}


