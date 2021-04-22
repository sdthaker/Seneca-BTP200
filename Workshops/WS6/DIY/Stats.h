// Workshop 6 DIY
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/28
//The below code is my own code except for professor provided code

#ifndef SDDS_STATS_H
#define SDDS_STATS_H

#include <iostream>

namespace sdds {

   class Stats {
       unsigned m_columnWidth = 0;
       unsigned m_noOfColumns = 0;
       unsigned m_precision = 0;
       double* m_number = nullptr;
       unsigned m_totalNum = 0;
       char* m_fileName = nullptr;
       double m_value = 0;
       void setEmpty();
       void setFilename(const char* fname, bool check = false);
       void setTotalNum();
       void loadNumber();
       void saveAs(const char* fileName) const;
       std::ostream& display(double* arr, unsigned totalNumbers,
                        std::ostream& ostr = std::cout) const;
       void setState(const Stats& other, const char* fileName, 
           unsigned columnWidth, unsigned noOfColumns, unsigned precision, 
           bool flag = false, bool check = false);
    public:
       Stats(unsigned columnWidth = 15, unsigned noOfColumns = 4,
             unsigned precision = 2);
       Stats(const char* filename, unsigned columnWidth = 15,
             unsigned noOfColumns = 4, unsigned precision = 2);
       Stats(const Stats& other);
       ~Stats();
       Stats& operator=(const Stats& other);
       double& operator[](unsigned idx);
       double operator[](unsigned idx) const;
       operator bool() const;
       void sort(bool ascending);
       unsigned size() const;
       const char* name() const;
       unsigned occurrence(double min, double max, 
                           std::ostream& ostr = std::cout);
       std::ostream& view(std::ostream& ostr) const;
       std::istream& getFile(std::istream& istr);
   };
   std::ostream& operator<<(std::ostream& os, const Stats& stat);
   std::istream& operator>>(std::istream& is, Stats& stats);
}

#endif