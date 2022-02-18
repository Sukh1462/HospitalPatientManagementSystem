/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	Sukhmanpreet Kaur
Revision History
-----------------------------------------------------------
Date      Reason
2020/7/31  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "Time.h"
#include "utils.h"
#include "Menu.h"
using namespace std;
namespace sdds {
	void Menu::display() const
	{
		cout << m_text << endl;
		cout << "0- Exit" << endl;

	}
	Menu::Menu(const char* MenuContent, int NoOfSelections){
		m_text = new char[strLen(MenuContent) + 1];
		strCpy(m_text, MenuContent);
		m_noOfSel = NoOfSelections;

	}
	Menu::Menu(const Menu& menu)
	{
		m_noOfSel = menu.m_noOfSel;

		if (menu.m_text) {
			m_text = new char[strLen(menu.m_text) + 1];
			strCpy(m_text, menu.m_text);
		}
		else m_text = nullptr;
	


	}
	Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;
	}
	int& Menu::operator>>(int& Selection)
	{
		display();
		int selection = getInt(0, m_noOfSel, "> ", "Invalid option ", true);
		Selection = selection;
		
		return Selection;
	}

}