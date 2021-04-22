// Workshop 4 DIY
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/07
//The below code is my own code and I have not taken any help in order to complete this workshop.

#include<iostream>
#include "Label.h"
#include "LabelMaker.h"

using namespace std;

namespace sdds {

    LabelMaker::LabelMaker()
    {
        m_label = nullptr;
        m_noOfLabels = 0;
    }
    LabelMaker::LabelMaker(int noOfLabels)
    {
        m_noOfLabels = noOfLabels;
        setLabel(noOfLabels);
    }
    LabelMaker::~LabelMaker()
    {
        delete[] m_label;
    }
    void LabelMaker::setLabel(int noOfLabels)
    {
          if (noOfLabels) {
                delete[] m_label;
                m_label = new Label[noOfLabels];
          }
    }
    void LabelMaker::readLabels()
    {
       if (m_noOfLabels) {

            cout << "Enter " << m_noOfLabels << " labels:" << endl;

            for (int i = 0; i < m_noOfLabels; i++) {
                 cout << "Enter label number " << i + 1 << endl << "> ";
                 m_label[i].readLabel();
            }
       }
    }
    void LabelMaker::printLabels()
    {
        for (int i = 0; i < m_noOfLabels; i++)
             m_label[i].printLabel() << endl;
    }

}