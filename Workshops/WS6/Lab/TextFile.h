// Workshop 6 Lab
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/21
//The below code is my own code except for professor provided code

#ifndef SDDS_TEXTFILE_H
#define SDDS_TEXTFILE_H
#include <iostream>

namespace sdds {

   class Line {
      char* m_value{nullptr};
      operator const char* ()const;
      Line() {}
      Line& operator=(const char*);
      ~Line();
      friend class TextFile;
      Line(const Line& L) = delete;
      Line& operator=(const Line& L) = delete;
   };

   class TextFile {
      Line* m_textLines = nullptr;
      char* m_fileName = nullptr;
      unsigned m_noOfLines = 0;
      unsigned m_pageSize = 0;
      void setFilename(const char* fname, bool isCopy = false);
      void setNoOfLines();
      void loadText();
      void saveAs(const char *fileName)const;
      void setEmpty();
      void setState(const TextFile& other, const char* fileName, 
                    bool flag = false, bool check = false);
   public:
      TextFile(unsigned pageSize = 15);
      TextFile(const char* filename, unsigned pageSize = 15);
      TextFile(const TextFile& other);
      TextFile& operator=(const TextFile& other);
      ~TextFile();
      std::ostream& view(std::ostream& ostr)const;
      std::istream& getFile(std::istream& istr);
      operator bool()const;
      unsigned lines()const;
      const char* name()const;
      const char* operator[](unsigned index)const;
   };
   std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
   std::istream& operator>>(std::istream& istr, TextFile& text);
}
#endif // !SDDS_TEXTFILE_H__