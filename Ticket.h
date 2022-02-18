/* Citation and Sources...
Final Project Milestone 5
Module: Ticket
Filename: Ticket.h
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

#ifndef SDDS_TICKET_H_
#define SDDS_TICKET_H_
#include "Time.h"
#include "IOAble.h"
namespace sdds {
   class Ticket:public IOAble{
      Time m_time;
      int m_number;
   public:
      Ticket(int number);
      operator Time()const;
      int number()const;
      void resetTime();
      virtual std::ostream& csvWrite(std::ostream& ostr)const;
      virtual std::istream& csvRead(std::istream& istr);
      virtual std::ostream& write(std::ostream& ostr )const;
      virtual std::istream& read(std::istream& istr);
   };
}
#endif // !SDDS_TICKET_H_
