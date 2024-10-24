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
#ifndef TRUCK_H
#define TRUCK_H
#include "MotorVehicle.h"
using namespace std;
namespace seneca {
	class Truck : public MotorVehicle {
		float m_capacity{};
		float m_current{};

	public:
		Truck() = default;
		Truck(const char licNo[9], int year, float capacity, const char address[64]) : MotorVehicle(licNo, year) {
			m_current = 0.0;
			m_capacity = capacity;
			moveTo(address);
		};
			bool addCargo(double cargo);
			bool unloadCargo();
			istream& read(istream& in=cin);
			ostream& write(ostream& os=cout)const;
			using MotorVehicle::write;
			using MotorVehicle::read;
			
	};
	ostream& operator<<(ostream & os, const Truck& other);
	istream& operator>>(istream& is, Truck& other);
}
#endif
