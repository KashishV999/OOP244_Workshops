/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 2
// Version 1.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Kahish Verma 25 May 2024      W2P1 
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"

using namespace seneca;
int main() {
   if (load()) {
      display();
   }
 
   deallocateMemory();
   return 0;
}
