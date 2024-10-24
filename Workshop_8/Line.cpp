/*/////////////////////////////////////////////////////////////////////////
Full Name  :Kashish Verma
Student ID#:151579232
Email      :kverma45@myseneca.ca
Date       :20 July  2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Line.h"
#include<string>
#include<cstring>
using namespace std;
namespace seneca {
	Line::Line():LblShape() {
		m_length = 0;
	}

	Line::Line(const char* value, int length) :LblShape(value) {
		m_length = length;
	}

	void Line:: getSpecs(istream& is) {
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore();
	}

	void Line::draw(ostream& os)const {
		if (m_length > 0 && label()) {
			cout << label()<<endl;
			for (int i = 0; i < m_length; i++) {
				cout << "=";
			}
		}
	}


}
