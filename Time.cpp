/* Citation and Sources...
Final Project Milestone 5
Module: Time
Filename: Time.cpp
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

#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Time& Time::setToNow()
	{
		this->m_min = getTime();
		return *this;
	}
	Time::Time(unsigned int min)
	{
		this->m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const
	{
		int hh = m_min / 60;
		int mm = m_min % 60;
		ostr.width(2);
		ostr.fill('0');
		ostr << hh;
		ostr << ":";
		ostr.width(2);
		ostr << mm;
		return ostr;
	}

	std::istream& Time::read(std::istream& istr)
	{
		int hh = 0;
		int mm = 0;
		char character = ',';
		istr >> hh >> character >> mm;

		if (hh < 0 || mm < 0 || character != ':') istr.setstate(ios::failbit);

		else m_min = hh * 60 + mm;
	

		return istr;

		
	}

	Time& Time::operator-=(const Time& D)
	{
		int x = D.m_min / (24 * 60);
		if (m_min > D.m_min) m_min -= D.m_min;
		else {
			int i, min = m_min;
			for (i = 0; i <= x; i++) {
				min += (24 * 60);

			}
			m_min = min - D.m_min;
		}
		
		return *this;
		
	}

	Time Time::operator-(const Time& D) const
	{
		Time t;
		int x = D.m_min / (24 * 60);
		
		if (m_min > D.m_min) t.m_min = m_min - D.m_min;
		else {
			int i, min = m_min;
			for (i = 0; i <= x; i++) {
				min += (24 * 60);
			}
			t.m_min = min - D.m_min;
		}
		return t;
	}

	Time& Time::operator+=(const Time& D)
	{
		m_min += D.m_min;
		return *this;
	}

	Time Time::operator+(const Time& D) const
	{
		Time t;
		t.m_min = m_min + D.m_min;
		return t;

	}

	Time& Time::operator=(unsigned int val)
	{
		m_min = val;
		return *this;
	}

	Time& Time::operator*=(unsigned int val)
	{
		m_min *= val;
		return *this;
	}

	Time& Time::operator/=(unsigned int val)
	{
		m_min /= val;
		return *this;
	}

	Time Time::operator*(unsigned int val) const
	{
		Time t;
		t.m_min = m_min * val;
		return t;

	}

	Time Time::operator/(unsigned int val) const
	{
		Time t;
		t.m_min = m_min / val;
		return t;
	}

	Time::operator unsigned int() const
	{
		return unsigned(m_min);
	}

	Time::operator int() const
	{
		return m_min;
	}

	





	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		D.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Time& D)
	{
		D.read(istr);
		return istr;
	}

}