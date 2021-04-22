// Workshop 10
// Name: Soham Thaker
// SID: 011-748-159
// Email: sdthaker1@myseneca.ca
// Date of Completion: 2021/04/05
// The below code is my own code except for professor provided code

#include <iostream>
#include <fstream>
#include "Text.h"
#include "cstring.h"

using namespace std;

namespace sdds {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   Text::Text(const char* filename) {
       if (filename) {
           delete[] m_filename;
           m_filename = alloc(filename);
           read();
       }
   }

   const char& Text::operator[](int index)const {
       return m_content[index];
   }

   Text::Text(const Text& Ro) {
      *this = Ro;
   }

   Text& Text::operator=(const Text& Ro) {
       if (this != &Ro) {
           delete[] m_filename;
           delete[] m_content;
           if (Ro.m_content) {
              m_filename = alloc(Ro.m_filename);
              m_content = alloc(Ro.m_content);
           }
           else {
               m_content = nullptr;
               m_filename = nullptr;
           }
       }
       return* this;
   }

   Text::~Text() {
       delete[] m_filename;
       delete[] m_content;
   }

   char* Text::alloc(const char* roData) const{
       char* data = nullptr;
       data = new char[strLen(roData) + 1];
       strCpy(data, roData);
       return data;
   }

   void Text::read() {
       delete[] m_content;
       m_content = new char[getFileLength() + 1];
       ifstream fin(m_filename);
       int i = 0;
       while (fin)
           m_content[i++] = fin.get();
       m_content[--i] = '\0';
   }

   void Text::write(ostream& os)const {
       if(m_content)
           os << m_content;
   }

   ostream& operator<<(ostream& os, const Text& Ro) {
       Ro.write(os);
       return os;
   }
}