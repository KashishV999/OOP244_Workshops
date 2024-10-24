/*/////////////////////////////////////////////////////////////////////////
Full Name  :Kashish Verma
Student ID#:151579232
Email      :kverma45@myseneca.ca
Date       :13 July 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/




#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include <iomanip>
#include "MotorVehicle.h"
using namespace std;
namespace seneca {
	MotorVehicle::MotorVehicle(const char licNo[9], int year) {
		strcpy(m_licNo, licNo);
		m_year = year;
		strcpy(m_address, "Factory");

	}

	void MotorVehicle::moveTo(const char* address)
	{
		if (strcmp(m_address, address) != 0) {
			
			cout << "|"<< setw(8) << right << m_licNo<< "| |";

			cout << setw(20) << right << m_address<< " ---> ";
			strcpy(m_address, address);
			cout << setw(20) << left << m_address<< "|"<<endl;

		

	
	
		}


	}

	ostream& MotorVehicle::write(ostream& os)const {
		// | [YEAR] | [PLATE] | [ADDRESS]
		os << "| ";
		os << m_year;
		os << " | ";
		os << m_licNo;
		os << " | ";
		os << m_address;
		return os;
	}

	istream& MotorVehicle::read(istream& in) {
		/*Built year: [USER TYPES HERE]
License plate: [USER TYPES HERE]
Current location: [USER TYPES HERE]*/

		
		cout << "Built year: ";
		in >> m_year;
		
		if (in.fail()) {
			in.clear();
			in.ignore(1000, '\n');
			cout << "CIN FAILED";
		}

		cout << "License plate: ";
		in >> m_licNo;
		
		if (in.fail()) {
			in.clear();
			in.ignore(1000, '\n');
			cout << "CIN FAILED";
		}

		cout << "Current location: ";
		in >> m_address;
		
		if (in.fail()) {
			in.clear();
			in.ignore(1000, '\n');
			cout << "CIN FAILED";
		}
		

		in.clear();
			return in;
	}





	ostream& operator<<(ostream& os, const MotorVehicle& other)
	{
		return other.write(os);
		//return os;
	}

	istream& operator>>(istream& is,   MotorVehicle& other) {
		return other.read(is);
		//return is;
	}



}
