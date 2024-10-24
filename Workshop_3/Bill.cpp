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
#include "Bill.h"

using namespace std;
namespace seneca {

	void Bill::setEmpty()
	{
		m_title[0] = '\0';
		m_items = nullptr;
	}

	bool Bill::isValid() const
	{
		int flag = 1;
		
		if (strlen(m_title) == 0 || m_items == nullptr)
		{
			flag = 0;
		}
		else {
			for (int i = 0; i < m_noOfItems && flag==1; i++) 
			{
				if (m_items[i].isValid() == false) {
					flag = 0;
				}
			}
		}		
		return flag == 1;
	}


	double Bill::totalTax() const
	{
		double finalAmount{};
		for (int i = 0; i < m_noOfItems; i++)
		{
			finalAmount+=m_items[i].tax();
		}
		return finalAmount;
	}

	double Bill::totalPrice() const
	{
		double finalPrice{};
		for (int i = 0; i < m_noOfItems; i++)
		{
			finalPrice+=m_items[i].price();
		}
		return finalPrice;
	}

	void Bill::Title() const
	{
		cout << "+--------------------------------------+" << endl;
		if (isValid())
		{
			cout << "| ";
			//m_title; left-justified in 36 spaces
			cout.width(36);
			cout.setf(ios::left);
			cout << m_title;
			cout.unsetf(ios::left);
			cout << " |"<<endl;
		}

		else {
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer() const
	{
		cout << "+----------------------+---------+-----+" << endl;
		if (isValid())
		{
			cout << "|                Total Tax: ";
			//totalTax(); right justified in 10 spaces with two digits after the decimal point
			cout.width(10);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalTax();
			cout.unsetf(ios::right);

			cout << " |"<<endl;
			cout << "|              Total Price: ";

			//totalPrice(); right justified in 10 spaces with two digits after the decimal point
			cout.width(10);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalPrice();
			cout.unsetf(ios::right);

			cout << " |" << endl;
			cout << "|          Total After Tax: ";

			//totalTax() + totalPrice(); right justified in 10 spaces with two digits after the decimal point
			cout.width(10);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalTax() + totalPrice();
			cout.unsetf(ios::right);

			cout << " |" << endl;
		}

		else {
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+--------------------------------------+" << endl;


	}

	//PUBLIC
	void Bill::init(const char* title, int noOfItems)
	{
		//arguments are invalid 
		if (title==nullptr || noOfItems<=0) {
			setEmpty();
		}

		//valid
		else {
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;

			strncpy(m_title, title, 36);

			//allocate memory
		       
			m_items = new Item[m_noOfItems];
			if (!(m_items)) {
			cout << "ALLOCATION FAILED";
			deallocate();
			}
			else{
				//Make sure all the dynamically allocated Items are set to empty
				for (int i = 0; i < m_noOfItems; i++)
				{
					m_items[i].setEmpty();
				}
			}

		}

	}

	bool Bill::add(const char* item_name, double price, bool taxed)
	{
		bool success = false;
		if (m_itemsAdded < m_noOfItems )
		{
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded += 1;
			success = true;
		}
		return success ;
	}


	void Bill::display() const
	{
		Title();
		for (int i = 0; i < m_noOfItems; i++)
		{
			m_items[i].display();
		}
		footer();
	}

	void Bill::deallocate()
	{
		delete[] m_items;
		m_items = nullptr;

	}



   








}
