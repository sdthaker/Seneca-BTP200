/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename:  PreTriage.h
Author	Soham Thaker
Revision History
-----------------------------------------------------------
Date        Reason
2021/03/28  Preliminary release
2021/04/08	Updated the dates for revision history, since all the files had year as 2020
----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_PRETRIAGE_H
#define SDDS_PRETRIAGE_H

#include "Patient.h"
#include "Time.h"
#include "Menu.h"

namespace sdds {

	const int maxNoOfPatients = 100;

	class PreTriage{
        Time
            m_averCovidWait,
            m_averTriageWait;
        Patient* m_lineup[maxNoOfPatients]{};
        char* m_dataFilename = nullptr;
        int m_lineupSize = 0;
        Menu
            m_appMenu,
            m_pMenu;
        void reg();
        void admit();
        const Time getWaitTime(const Patient& p)const;
        void setAverageWaitTime(const Patient& p);
        void removePatientFromLineup(int index);
        int indexOfFirstInLine(char type) const;
        void load();
        void commonReg();
        void commonAdmit(int i);
    public:
        PreTriage(const char* dataFilename);
        ~PreTriage();
        void run();
	};
}

#endif