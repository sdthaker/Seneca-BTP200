// Workshop 10
// Name: Soham Thaker
// SID: 011-748-159
// Email: sdthaker1@myseneca.ca
// Date of Completion: 2021/04/05
// The below code is my own code except for professor provided code

#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H

#include <iostream>
#include "Text.h"

namespace sdds {
   class HtmlText :  public Text {
       char* m_title = nullptr;
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);
      HtmlText(const HtmlText& Ro);
      HtmlText& operator=(const HtmlText& Ro);
      ~HtmlText();
      virtual void write(std::ostream& os)const;
   };
   std::ostream& operator<<(std::ostream& os, const HtmlText& Ro);
}
#endif // !SDDS_HTMLTEXT_H__
