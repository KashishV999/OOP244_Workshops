/*/////////////////////////////////////////////////////////////////////////
Full Name  :Kashish Verma
Student ID#:151579232
Email      :kverma45@myseneca.ca
Date       :13 July 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/




#pragma once
#ifndef MOTOR_VEHICLE
#define MOTOR_VEHICLE
#include<iostream>
using namespace std;
namespace seneca {

	class MotorVehicle {
		char m_licNo[9]{};
		char m_address[64]{};
		int m_year{};

	public:
		MotorVehicle()=default;
		MotorVehicle(const char licNo[9], int year);
		void moveTo(const char* address);
		ostream& write(ostream& os=cout)const;
		istream& read(istream& in=cin);
	};

	ostream& operator<<(ostream& os, const MotorVehicle& other);
	istream& operator>>(istream& is,   MotorVehicle& other);

}

#endif
