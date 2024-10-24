/*/////////////////////////////////////////////////////////////////////////
Full Name  :Kashish Verma
Student ID#:151579232
Email      :kverma45@myseneca.ca
Date       :June 15 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   //type conversion operators
   Account::operator bool()const {
       if (m_number >= 10000 && m_number <= 99999
           && m_balance >= 0.0) {
           return true;
       }
       else {
           return false;
       }
   }

   Account::operator int()const {
       return m_number;
   }

   Account::operator double()const {
       return m_balance;
   }

   //Unary member operator
   // true is the account is new or not set 
   bool Account::operator~() const
   {
       return m_number == 0;
   }

   Account& Account::operator=(int value)
   {
       if ( (~*this)) {

           if(value >= 10000 && value <= 99999 && value > 0)
                m_number = value;

           else {
               setEmpty();
           }
       }
       return *this;
   }

   Account& Account::operator=(Account& Roper)
   {
       if ((~(*this)) && (Roper)) {
           m_number = Roper.m_number;
           m_balance = Roper.m_balance;
           Roper.m_number = 0;
           Roper.m_balance = 0.0;
       }
       return *this;
   }

   Account& Account::operator+=(double value)
   {
       if (value >= 0 && (*this)) {
           m_balance += value;
       }
       return *this;
   }

   Account& Account::operator-=(double value)
   {
       if (value >= 0 && (*this) && m_balance >= value) {
           m_balance -= value;
       }
       return *this;
   }

   Account& Account::operator<<(Account& Roper)
   {
       if ((*this) && (Roper) && (m_number != Roper.m_number)) {
           m_balance = m_balance+ Roper.m_balance;
           Roper.m_balance = 0.0;
       }
       return *this;
   }

   Account& Account::operator>>(Account& Roper)
   {
       if ((*this) && (Roper) && (m_number != Roper.m_number)) {
           Roper.m_balance =Roper.m_balance+ m_balance;
           m_balance = 0.0;
       }
       return *this;
   }





   //Binary member operators
   //All the binary member operators will not take any action if the account is in an invalid state.


   double operator+(const Account& Loper, const Account& Roper)
   {
       double sum{};
       if ((Loper) && (Roper)) {
           double balance1 = Loper;
           double balance2 = Roper;
           sum = balance1 + balance2;
       }
       else {
           sum = 0.0;
       }
       return sum;
   }

   double operator+=(double& value, const Account Roper)
   {
       
       double balance1 = Roper;
       value += balance1;
       return value;
   }


}
