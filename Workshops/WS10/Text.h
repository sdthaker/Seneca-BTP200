// Workshop 10
// Name: Soham Thaker
// SID: 011-748-159
// Email: sdthaker1@myseneca.ca
// Date of Completion: 2021/04/05
// The below code is my own code except for professor provided code

#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H

#include <iostream>

namespace sdds {
   class Text {
      char* m_filename = nullptr;
      char* m_content = nullptr;
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
      char* alloc(const char* roData) const;
   public:
      Text(const char* filename=nullptr);
      Text(const Text& Ro);
      Text& operator=(const Text & Ro);
      virtual ~Text();
      void read();
      virtual void write(std::ostream& os)const;
   };
   std::ostream& operator<<(std::ostream& os, const Text& Ro);
}
#endif // !SDDS_PERSON_H__

