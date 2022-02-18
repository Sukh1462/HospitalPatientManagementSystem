/* Citation and Sources...
Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.cpp
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

#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
namespace sdds {
	int nextTriageTicket = 1;

	TriagePatient::TriagePatient() :Patient(nextTriageTicket)
	{
		m_symptoms = nullptr;
		nextTriageTicket++;
	}

	char TriagePatient::type()const
	{
		return 'T';
	}

	std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const
	{
		Patient::csvWrite(ostr);
		ostr << "," << m_symptoms;
		return ostr;
	}

	std::istream& TriagePatient::csvRead(std::istream& istr)
	{
		delete[] m_symptoms;
		Patient::csvRead(istr);
		char ch;
		istr >> ch;
		m_symptoms = getcstr(nullptr, istr, '\n');
		
		nextTriageTicket = Patient::number() + 1;
		return istr;

	}

	std::ostream& TriagePatient::write(std::ostream& ostr) const
	{
		if (fileIO()) csvWrite(ostr);
		else {
			ostr << "TRIAGE" << std::endl;
			Patient::write(ostr);
			ostr << std::endl;
			ostr << "Symptoms: ";
			ostr << m_symptoms << std::endl;

		}
		return ostr;
	}

	std::istream& TriagePatient::read(std::istream& istr)
	{
		if (fileIO()) csvRead(istr);
		else {
			delete[] m_symptoms;
			Patient::read(istr);
			m_symptoms = getcstr("Symptoms: ", istr, '\n');

		}
		return istr;
	}

	TriagePatient::~TriagePatient()
	{
		delete[] m_symptoms;
	}

}