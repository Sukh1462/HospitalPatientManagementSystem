/* Citation and Sources...
Final Project Milestone 5
Module: Patient
Filename: Patient.cpp
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
#include "string.h"
#include "Time.h"
#include "utils.h"
#include "IOAble.h"
#include "Ticket.h"
#include "Patient.h"


using namespace std;
namespace sdds {
	Patient::Patient(int ticketNumber, bool fileIO):m_ticket(0)
	{
		m_ticket = ticketNumber;
		m_fileIO = fileIO;
		m_name = nullptr;
		
	}
	Patient::~Patient()
	{
		delete[] m_name;
		m_name = nullptr;
	}

	bool Patient::fileIO() const
	{
		return m_fileIO;
	}
	void Patient::fileIO(bool flag)
	{
		m_fileIO = flag;
	}
	bool Patient::operator==(const char ptype)const
	{

		return (ptype == type());
			
	}
	bool Patient::operator==(const Patient& patient) const
	{
		
		return (type() == patient.type());
	}
	void Patient::setArrivalTime()
	{
		m_ticket.resetTime();
	}

	Patient::operator Time() const
	{
		return Time(m_ticket);
	}

	int Patient::number() const
	{
		return m_ticket.number();
	}

	ostream& Patient::csvWrite(ostream& ostr) const
	{
		ostr << type() <<","<< m_name <<","<< m_OHIP<<",";
		m_ticket.csvWrite(ostr);
		return ostr;
	}

	istream& Patient::csvRead(istream& istr)
	{
		char delimiter;
	
		delete[] m_name;
		
		m_name=getcstr(nullptr, istr, ',');

		istr >> m_OHIP;
		
		istr >> delimiter;
		m_ticket.csvRead(istr);
		return istr;
		
	}

	ostream& Patient::write(ostream& ostr) const
	{
		m_ticket.write(ostr);
		ostr << endl;
		int i;
		for (i = 0; i < 25&&m_name[i]!=0; i++) {
			ostr << m_name[i];
		}
		ostr << ", OHIP: " << m_OHIP;

		return ostr;

	}

	std::istream& Patient::read(std::istream& istr)
	{
	
		delete[] m_name;
		
		m_name=getcstr("Name: ", istr, '\n');
		m_OHIP = 0;
		m_OHIP = getInt(100000000, 999999999, "OHIP: ", "Invalid OHIP Number, ", true);
		return istr;
	}



	


}

