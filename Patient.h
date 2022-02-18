/* Citation and Sources...
Final Project Milestone 5
Module: Patient
Filename: Patient.h
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
#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H
#include "IOAble.h"
#include "Ticket.h"
namespace sdds {
	class Patient :public IOAble {
		char* m_name;
		int m_OHIP;
		Ticket m_ticket;
		bool m_fileIO;
	public:
		Patient(int ticketNumber=0,bool fileIO=false);
		Patient(const Patient& patient) = delete;
		Patient& operator=(const Patient& patient) = delete;
		~Patient();
		virtual char type()const = 0;
		bool fileIO()const;
		void fileIO(bool flag);
		bool operator==(const char ptype)const;
		bool operator==(const Patient& patient)const;
		void setArrivalTime();
		operator Time()const;
		int number()const;
		virtual std::ostream& csvWrite(std::ostream& ostr)const;
		virtual std::istream& csvRead(std::istream& istr);
		virtual std::ostream& write(std::ostream& ostr)const;
		virtual std::istream& read(std::istream& istr);

	};
}
#endif

