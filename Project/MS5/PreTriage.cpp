/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
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

#include <iostream>
#include <fstream>
#include <cstring>
#include "PreTriage.h"
#include "TriagePatient.h"
#include "CovidPatient.h"
#include "utils.h"

using namespace std;

namespace sdds {

	PreTriage::PreTriage(const char* dataFilename) : 
		m_averCovidWait{ 15 }, m_averTriageWait{ 5 },
		m_appMenu
	{ "General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2 }, 
		m_pMenu{ "Select Type of Admittance:\n1- Covid Test\n2- Triage", 2 }
		{
		delete[] m_dataFilename;
		m_dataFilename = new char[strlen(dataFilename) + 1];
		strcpy(m_dataFilename, dataFilename);
		load();
	}

	PreTriage::~PreTriage() {

		ofstream fout(m_dataFilename);

		if (fout.is_open() && fout) {
			fout << m_averCovidWait << ',' << m_averTriageWait << endl;

			cout << "Saving Average Wait Times," << endl;
			cout << "   COVID Test: " << m_averCovidWait << endl;
			cout << "   Triage: " << m_averTriageWait << endl;

			cout << "Saving m_lineup..." << endl;
			for (int i = 0; i < m_lineupSize; i++) {
				m_lineup[i]->csvWrite(fout) << endl;
				cout << i + 1 << "- ";
				m_lineup[i]->fileIO(true);
				m_lineup[i]->write(cout) << endl;
			}
		}

		for (int i = 0; i < maxNoOfPatients; i++)
			delete m_lineup[i];

		delete[] m_dataFilename;
		cout << "done!" << endl;
		fout.close();
	}

	const Time PreTriage::getWaitTime(const Patient& p)const {

		int waitTime = 0, noOfPatient = 0;
		char type = 0;
		Time totalWaitTime(0);

		if (p.type() == 'C') {
			waitTime = int(m_averCovidWait);
			type = 'C';
		}
		else if (p.type() == 'T') {
			waitTime = int(m_averTriageWait);
			type = 'T';
		}

		for (int i = 0; i < m_lineupSize; i++) {
			if (m_lineup[i]->type() == type)
				noOfPatient++;
		}
		return totalWaitTime = noOfPatient * waitTime;
	}

	void PreTriage::setAverageWaitTime(const Patient& p) {
		if (p.type() == 'C')
			m_averCovidWait = (((unsigned)getTime() - (unsigned)Time(p)) +
							  ((unsigned)m_averCovidWait * (unsigned)(p.number() - 1))) /
							  (unsigned)p.number();
		else if (p.type() == 'T')
			m_averTriageWait = (((unsigned)getTime() - (unsigned)Time(p)) +
							   ((unsigned)m_averTriageWait * (unsigned)(p.number() - 1))) /
							   (unsigned)p.number();
	}

	void PreTriage::removePatientFromLineup(int index) {
		removeDynamicElement<Patient>(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const {
		for (int i = 0; i < m_lineupSize; i++) {
			if (m_lineup[i]->type() == type)
				return i;
		}
		return -1;
	}

	void PreTriage::load() {

		Patient* p = nullptr;
		ifstream fin(m_dataFilename);
		char type;
		bool flag = true;
		int i = 0;

		cout << "Loading data..." << endl;

		if (fin.is_open()) {
			fin >> m_averCovidWait;
			fin.ignore();
			fin >> m_averTriageWait;
			fin.ignore();

			if (fin) {
				for (i = 0; i < maxNoOfPatients && flag; i++) {
					fin >> type;
					if (fin) {
						fin.ignore();

						if (type == 'C')
							p = new CovidPatient();
						else if (type == 'T')
							p = new TriagePatient();

						if (p) {
							p->fileIO(true);
							p->read(fin);
							p->fileIO(false);
							m_lineup[i] = p;
							m_lineupSize++;
						}
					}
					else
						flag = false;
				}
			}

			if (!p) {
				cout << "No data or bad data file!" << endl << endl;
				fin.clear();
			}
			else if (i + 1 < maxNoOfPatients) {
				cout << m_lineupSize << " Records imported..." << endl << endl;
			}
			else if (fin) {
				cout << "Warning: number of records exceeded " << maxNoOfPatients << endl 
					 << m_lineupSize << " Records imported..." << endl << endl;
			}
		}
		fin.close();
	}

	void PreTriage::commonReg(){
		m_lineup[m_lineupSize]->setArrivalTime();
		cout << "Please enter patient information: " << endl;
		m_lineup[m_lineupSize]->fileIO(false);
		m_lineup[m_lineupSize]->read(cin);
		cout << endl << "******************************************" 
			 << endl;
		m_lineup[m_lineupSize]->write(cout) << "Estimated Wait Time: " 
			    << getWaitTime(*m_lineup[m_lineupSize]) << endl 
			    << "******************************************" << endl << endl;
		m_lineupSize++;
	}

	void PreTriage::reg() {

		int selection = 0;

		if (m_lineupSize == maxNoOfPatients) {
			cout << "Line up full!" << endl;
		}
		else {
			m_pMenu >> selection;
			
			if (selection == 1) {
				m_lineup[m_lineupSize] = new CovidPatient();
				commonReg();
			}
			else if (selection == 2) {
				m_lineup[m_lineupSize] = new TriagePatient();
				commonReg();
			}
		}
	}

	void PreTriage::commonAdmit(int i){
		if (i != -1) {
			cout << endl << "******************************************" 
				 << endl;
			m_lineup[i]->fileIO(false);
			cout << "Calling for ";
			m_lineup[i]->write(cout) << "******************************************"
				                     << endl << endl;
			setAverageWaitTime(*m_lineup[i]);
			removePatientFromLineup(i);
		}
	}

	void PreTriage::admit() {
		int selection = 0, i = -1;
		m_pMenu >> selection;

		if (selection == 1) {
			i = indexOfFirstInLine('C');
			commonAdmit(i);
		}
		else if (selection == 2) {
			i = indexOfFirstInLine('T');
			commonAdmit(i);
		}
	}

	void PreTriage::run() {
		int selection = 1;

		while (selection) {
			m_appMenu >> selection;
			if (selection == 1)
				reg();
			else if (selection == 2)
				admit();
		}
	}
}