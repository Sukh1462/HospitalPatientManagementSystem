/* Citation and Sources...
Final Project Milestone 5
Module: utils
Filename: utils.cpp
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


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;  // made global in utils.h
   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }
   int getInt(const char* prompt)
   {
       int integerValue;
       char newline='x';
       int done = 0;
       if (prompt) cout << prompt;
 
       do {
           done = 0;
           cin >> integerValue;
           if (cin.fail()) {
               cout << "Bad integer value, try again: ";
               cin.clear();
               cin.ignore(10000, '\n');
               

           }
           else {

               cin.get(newline);

               if (newline != '\n') {
                   cin.clear();
                   cin.ignore(10000, '\n');
                   cout << "Enter only an integer, try again: ";
                   
               }
               else done = 1;
           }
       } while (!done);       

       return integerValue;
   }
   int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
   {
       int integerValue;
       char newline = 'x';
       int done = 0;
       if (prompt) cout << prompt;

       do {
           
          
           done = 0;
           cin >> integerValue;
           if (cin.fail()) {
               cout << "Bad integer value, try again: ";
               cin.clear();
               cin.ignore(10000, '\n');


           }
           else {

               cin.get(newline);

               if (newline != '\n') {
                   cin.clear();
                   cin.ignore(10000, '\n');
                   cout << "Enter only an integer, try again: ";

               }
               else {

                   if (integerValue >= min && integerValue <= max) {
                       done = 1;
                   }
                   else {
                     
                       if (errorMessage) {
                           cout << errorMessage;
                           if (showRangeAtError) {
                               cout << "[" << min << " <= value <= " << max << "]: ";
                           }
                       }

                   }

               }

           }
           
       } while (!done);

       return integerValue;
   }
   char* getcstr(const char* prompt, std::istream& istr, char delimiter)
   {
       if (prompt) cout << prompt;
       char* s=nullptr;
       string str;
       if (getline(istr, str,delimiter)) {
           s = new char[str.length() + 1];
           strcpy(s, str.c_str());
       }

       return s;
   }

   int strLen(const char* s) {

       int i = 0;
       for (i = 0; s[i] != '\0'; i++);
       return i;
   }

   void strCpy(char* des, const char* src) {
       int i = 0;
       for (i = 0; src[i] != '\0'; i++) des[i] = src[i];
       des[i] = '\0';
   }
}


