/* Citation and Sources...
Final Project Milestone 5
Module: IOAble
Filename: IOAble.cpp
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
#include "IOAble.h"

using namespace std;
namespace sdds {

	std::ostream& operator<<(std::ostream& os, const IOAble& io)
	{
		io.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, IOAble& io)
	{
		io.read(is);
		return is;
	}
}
