/*/////////////////////////////////////////////////////////////////////////
Full Name  :Kashish Verma
Student ID#:151579232
Email      :kverma45@myseneca.ca
Date       :01 June 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Item.h"
using namespace std;
char m_itemName[21];
namespace seneca {
    void Item::setName(const char* name)
    {
        strncpy(m_itemName, name,20);
    }

    void Item::setEmpty()
    {
        m_price = 0.0;
        m_itemName[0] = '\0';

    }

    void Item::set(const char* name, double price, bool taxed)
    {
        m_taxed = taxed;
        if (price < 0 || name==nullptr) {
            setEmpty();
        }
        else {
            setName(name);
            m_price = price;
        }
    }

    double Item::price() const
    {
        return m_price;
    }

    double Item::tax() const
    {
        double finalTax{};
        if (m_taxed) {
            finalTax = m_price * 0.13;
        }
        else {
            finalTax = 0.0;
        }
        return finalTax;
    }

    bool Item::isValid() const
    {
        bool success = false;
        if (m_price != 0.0 && m_itemName[0] != '\0') {
           success = true;
          
        }
        return success;
    }

    void Item::display() const
    {
        if (isValid()) {
            cout << "| ";
            //m_itemName; left-justified in 20 spaces, padded with '.' (dots)
            cout.setf(ios::left);
            cout.width(20);
            cout.fill('.');
            cout << m_itemName;
            cout.unsetf(ios::left);
            cout.fill(' ');

            cout << " | ";

            //m_price; right-justified in 7 spaces with two digits after the decimal point
            cout.width(7);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << m_price;
            cout.unsetf(ios::right);
           

            cout << " | ";

            //if m_taxed is true prints "Yes" otherwise prints "No "
            if (m_taxed) {
                cout << "Yes";
            }
            else {
                cout << "No ";
            }

            cout << " |" << endl;

        }
        else {

            cout<<  "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;

        }

    }


 

}
