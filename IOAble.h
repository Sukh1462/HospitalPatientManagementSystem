/* Citation and Sources...
Final Project Milestone 5
Module: IOAble
Filename: IOAble.h
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
#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
#include <iostream>
namespace sdds {
	class IOAble {
	public:
		virtual std::ostream& csvWrite(std::ostream& ostr)const=0;

		virtual std::istream& csvRead(std::istream& istr)=0;

		virtual std::ostream& write(std::ostream& ostr)const=0;

		virtual std::istream& read(std::istream& istr)=0;

		virtual ~IOAble() {};

	};

	std::ostream& operator<<(std::ostream& os, const IOAble& io);
	std::istream& operator>>(std::istream& is, IOAble& io);
}

#endif

