/*/////////////////////////////////////////////////////////////////////////
Full Name  :Kashish Verma
Student ID#:151579232
Email      :kverma45@myseneca.ca
Date       :15 June 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      //Type Conversion Operator
      // 
      //returns true if the account is valid 
      operator bool()const;
      operator int()const;
      operator double()const;
      //eturns true is the account is new or not set
      bool operator~() const;
      Account& operator=(int value);
      Account& operator=(Account& Roper);
      Account& operator+=(double value);
      Account& operator-=(double value);
      Account& operator<<(Account& Roper);
      Account& operator>>(Account& Roper);

   };

   double operator+(const Account& Loper, const Account& Roper);
   double operator+=(double& value, const Account Roper);

   
}
#endif // SENECA_ACCOUNT_H_

/*    
  

          
      */
