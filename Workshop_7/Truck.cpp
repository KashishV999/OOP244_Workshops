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
#include "Truck.h" 
#include <iomanip>
using namespace std;
namespace seneca {



	/*
	Truck::Truck(const char licNo[9], int year, float capacity, const char address[50])
	{
		m_current = 0.0;
		m_capacity = capacity;
		moveTo(address);
	}*/

	bool Truck::addCargo(double cargo) {
		bool success = false;
		if (m_current != m_capacity) {
			if (cargo <= (m_capacity - m_current)) {
				m_current += cargo;
			}
			else {
				m_current = m_capacity;
			}
			success = true;
		}
	
		return success;
	}

	bool Truck:: unloadCargo() {
		bool success = false;
		if (m_current) {
			m_current = 0;
			success = true;
		}
		return success;
	}

	istream& Truck::read(istream& in) {
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> m_capacity;

		if (in.fail()) {
			in.clear();
			in.ignore(1000, '\n');
			cout << "CIN FAILED";
		}

		cout << "Cargo: ";
		in >> m_current;

		if (in.fail()) {
			in.clear();
			in.ignore(1000, '\n');
			cout << "CIN FAILED";
		}
		in.clear();
		return in;
	}

	ostream& Truck::write(ostream& os)const {
		/*| [YEAR] | [PLATE] | [ADDRESS]*/
		MotorVehicle::write(os);
		os << " | ";
		os << m_current;
		os << "/";
		os << m_capacity;
		return os;
	}
	
	ostream& operator<<(ostream& os, const Truck& other) {
		return other.write(os);
		//return os;
	}
	istream& operator>>(istream& is, Truck& other) {
		return other.read(is);
		//return is;
	}

}
