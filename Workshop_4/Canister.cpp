/*/////////////////////////////////////////////////////////////////////////
Full Name  :Kashish Verma
Student ID#:151579232
Email      :kverma45@myseneca.ca
Date       :7 June 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

 #define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <cstring>
#include "Canister.h"
using namespace std;
//(a global constant double value created in Canister.cpp)
const double PI = 3.14159265;

namespace seneca {
	void Canister::setToDefault()
	{
		m_contentName = nullptr;
		m_height = 13.0;
		m_diameter = 10.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}


	void Canister::setName(const char* Cstr)
	{
		//copy the name of 'Apple' to "Orange canister"
		if (Cstr != nullptr && this->m_usable) {
			delete[] this->m_contentName;
			//dynamic memory allocation
			m_contentName = new char[strlen(Cstr) + 1];
			strcpy(this->m_contentName, Cstr);
		}
	}


	bool Canister::isEmpty() const
	{
		bool success = false;
		if (m_contentVolume < 0.00001) {
			success = true;
		}
		return success;
	}

	
	bool Canister::hasSameContent(const Canister& C) const
	{	
		if (this->m_contentName != nullptr && C.m_contentName != nullptr) {
			return 0==strcmp(this->m_contentName, C.m_contentName);
		}
		else {
			return false;
		}
	}


	//If any of the dimensions have invalid values, it will set the Canister as unusable
	Canister::Canister()
	{
		setToDefault();
	}

	Canister::Canister(const char* contentName)
	{
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double height, double diameter, const char* contentName)
	{
		setToDefault();
		//height and diameter of 10.0 by 10.0 centimetres and the largest one can be 40 by 30 respectively.
		if (height >= 10 && height <= 40 && diameter >= 10 && diameter <= 30) {
			m_height = height;
			m_diameter = diameter;
			setName(contentName);
			m_contentVolume = 0.0;
		}
		else {
			m_usable = false;
		}
	}

	Canister::~Canister()
	{
		clear();
	}



	//PUBLIC
	void Canister::clear()
	{
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;
	}


	double Canister::capacity() const
	{
		//returns the capacity
		//Capacity = PI x (H - 0.267) x (D/2) x (D/2)
		double maxCapacity{};
		maxCapacity = PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
		return maxCapacity;
	}


	double Canister::volume() const
	{
		return m_contentVolume;
	}



	
	Canister& Canister::setContent(const char* contentName)
	{
		//if (hasSameContent(const Canister& C)==false)
		if (contentName == nullptr) {
			m_usable = false;
		}

		else if (isEmpty()) {
			setName(contentName);
		}

		else if (hasSameContent(contentName) == false)
		{
			m_usable = false;
		}

		
		// TODO: insert return statement here
		return *this;
	}

	Canister& Canister::pour(double quantity)
	{
		if (quantity > 0.0 && m_usable && ((m_contentVolume + quantity) <= capacity())) {
			m_contentVolume += quantity;
		}
		else {
			m_usable = false;
		}
		// TODO: insert return statement here
		return *this;
	}


	Canister& Canister::pour(Canister& C)
	{
		setContent(C.m_contentName);
		if (C.volume() > (this->capacity() - this->volume())) {
			C.m_contentVolume-= capacity() - volume();
			//then set the content volume to capacity()
			this->m_contentVolume = this->capacity();
		}
		else {
			pour(C.m_contentVolume);
			C.m_contentVolume  = 0.0;
		}
		// TODO: insert return statement here
		return *this;
	}

	
	 std::ostream& Canister:: display()const
	{
		
		cout.width(7);
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << this->capacity();
		cout << "cc (";
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << m_height;
		cout << "x";
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << this->m_diameter;
		cout << ") Canister";
			
		if(m_usable==false){
			cout << " of Unusable content, discard!";
		}
		else if(this->m_contentName!=nullptr){
			cout << " of ";
			cout.width(7);
			cout.setf(ios::fixed);
			cout.precision(1);
			cout << this->volume();
			cout << "cc   ";
			cout << this->m_contentName;
		}

		//insert return statement here
		return cout;
	}






}
