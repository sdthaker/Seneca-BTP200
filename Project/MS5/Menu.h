/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
Author	Soham Thaker
Revision History
-----------------------------------------------------------
Date        Reason
2002/03/18  Preliminary release
2020/03/24  Updated >> operator overload to use 
            pre existing getInt() function from utils.cpp
2021/04/08	Updated the dates for revision history, since all the files had year as 2020
2021/04/11	Updated the Menu.cpp file to include utils.h from Menu.h

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds {
    class Menu {
        char* m_text = nullptr;
        int m_noOfSel = 0;
        void display()const;
    public:
        Menu(const char* MenuContent, int NoOfSelections);
        Menu(const Menu& Ro) : Menu(Ro.m_text, Ro.m_noOfSel) {}
        virtual ~Menu();
        int& operator>>(int& Selection);
        Menu& operator=(const Menu& Ro) = delete;
    };
}

#endif // !SDDS_MENU_H

