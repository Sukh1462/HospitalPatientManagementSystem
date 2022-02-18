/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
Version 1.0
Author	Sukhmanpreet Kaur
Revision History
-----------------------------------------------------------
Date      Reason
2021/07/31  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <fstream>
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "PreTriage.h"
using namespace std;
namespace sdds {

	PreTriage::PreTriage(const char* dataFilename) : m_averCovidWait(15), m_averTriageWait(5), m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
	{

		m_dataFilename = new char[strLen(dataFilename) + 1];
		strCpy(m_dataFilename, dataFilename);



		load();

	}


	PreTriage::~PreTriage()
	{
		ofstream fout;
		fout.open((m_dataFilename));


		if (fout.is_open()) {
			fout << m_averCovidWait << ',' << m_averTriageWait << endl;
			//m_averCovidWait.write(fout);
			//fout << ',';
			//m_averTriageWait.write(fout);
			//fout << endl;


			cout << "Saving Average Wait Times," << endl;
			cout << "   COVID Test: " << m_averCovidWait << endl;
			cout << "   Triage: " << m_averTriageWait << endl;
			int i;
			cout << "Saving m_lineup..." << endl;

			for (i = 0; i < m_lineupSize; i++) {
				if (m_lineup[i] != nullptr) {
					m_lineup[i]->csvWrite(fout);
					fout << endl;
					cout << i + 1 << "- ";
					m_lineup[i]->csvWrite(cout);
					cout << endl;

				}

			}

			for (i = 0; i < m_lineupSize; i++) delete m_lineup[i];
			delete[] m_dataFilename;
			cout << "done!"<<endl;


		}
		else cout << "could not open file for writing, from the destructor ~Pre-Triage" << endl;



	}


	void PreTriage::run(void)
	{
		int selection, done = 0;
		do {
			m_appMenu >> selection;

			if (selection == 1) reg();
			else if (selection == 2) admit();
			else if (selection == 0) done = 1;
		} while (done == 0);

	}


	void PreTriage::reg()
	{

		if (m_lineupSize == maxNoOfPatients) cout << "Line up full!" << endl;
		else {
			int selection;
			m_pMenu >> selection;
			if (selection == 1) {
		
				m_lineup[m_lineupSize] = new CovidPatient();

			}
			else if (selection == 2) {
			
				m_lineup[m_lineupSize] = new TriagePatient();

			}
			else if (selection == 0) {
				//do nothing
			};

			if (selection == 1 || selection == 2) {
				m_lineup[m_lineupSize]->setArrivalTime();
				cout << "Please enter patient information: " << endl;
				m_lineup[m_lineupSize]->fileIO(false);

				m_lineup[m_lineupSize]->read(cin);
				cout << endl << "******************************************" << endl;
				m_lineup[m_lineupSize]->write(cout);
				cout << "Estimated Wait Time: ";
				cout << getWaitTime(*m_lineup[m_lineupSize]) << endl;
				cout << "******************************************" << endl << endl;
				m_lineupSize++;
				

			}
		}
	}


	void PreTriage::admit()
	{
		int selection;
		m_pMenu >> selection;
		char ptype = 'X';
		if (selection == 1) ptype = 'C';
		else if (selection == 2) ptype = 'T';
		else if (selection == 3) {
			//do nothing
		};
		if (selection != 0) {
			int index = indexOfFirstInLine(ptype);
			if (index != -1) {
				cout << endl << "******************************************" << endl;
				m_lineup[index]->fileIO(false);
				cout << "Calling for " << *m_lineup[index];
				cout << "******************************************" << endl << endl;
				setAverageWaitTime(*m_lineup[index]);


				removePatientFromLineup(index);


			}


		}

	}


	const Time PreTriage::getWaitTime(const Patient& p) const
	{
		int i, counter = 0;
		for (i = 0; i < m_lineupSize; i++) {
			if (p.type() == m_lineup[i]->type()) counter++;
		}
		Time waitTime;
		//why did i need to use operator*
		if (p.type() == 'T') waitTime = (m_averTriageWait.operator*(counter));
		else waitTime = (m_averCovidWait.operator*(counter));
		return waitTime;
	}


	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		Time* awt;
		Time ct = getTime();
		Time ptt = Time(p);
		int ptn = p.number();

		awt = p.type() == 'T' ? &m_averTriageWait : &m_averCovidWait;

		*awt = ((ct - ptt) + (awt->operator*(ptn - 1))).operator/(ptn);


	}


	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}


	int PreTriage::indexOfFirstInLine(char type) const
	{
		
		int i, index = -1;
		for (i = 0; i < m_lineupSize && index == -1; i++) {
			//if (type == m_lineup[i]->type()) index = i;
			if (*m_lineup[i] == type) index = i;
		}

		return index;


	}


	void PreTriage::load()
	{
		cout << "Loading data..." << endl;
		ifstream fin;
		fin.open(m_dataFilename);

		if (fin.is_open()) {
			fin >> m_averCovidWait;
			char ch = ',';
		
			fin >> ch;
			fin >> m_averTriageWait;

			Patient* pp = nullptr;
			int i;
			for (i = 0; i < maxNoOfPatients; i++) {
				if (fin.good()) {
					char ptype;
					fin >> ptype;
					//ptype = fin.get();
					char ch;
					
					if (ptype == 'C') {
				
						pp = new CovidPatient();

					}
					else if (ptype == 'T') {
						
						pp = new TriagePatient();
					}
					
					else {
						pp = nullptr;
						break;
					}
					ptype = 'X';

					if (pp) {
						fin >> ch;
						pp->fileIO(true);
						fin >> (*pp);
						pp->fileIO(false);
						m_lineup[i] = pp;

						m_lineupSize++;
					}
				}



			}
			if (i == maxNoOfPatients && fin.good()) cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;

			if (m_lineupSize == 0) cout << "No data or bad data file!" << endl << endl;
			else cout << m_lineupSize << " Records imported..." << endl << endl;

		}
		else cout << "couldn't open file from preTriage::load()" << endl;
	}
}
