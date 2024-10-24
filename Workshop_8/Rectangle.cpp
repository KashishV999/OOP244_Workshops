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
#include "Rectangle.h"
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;
namespace seneca {
	Rectangle::Rectangle():LblShape() {
		m_height = 0;
		m_width = 0;
	}

	Rectangle::Rectangle(const char* value, int width, int height):LblShape(value) {
		m_width = width;
		m_height = height;
			if (m_height < 3 || (m_width < (strlen(label()) + 2))) {
			m_height = 0;
			m_width = 0;
			}
		
		
		
	}


	void Rectangle:: getSpecs(istream& is) {
		LblShape::getSpecs(is);
		is >> m_width;
		is.ignore();
		is >> m_height;
		is.ignore();
		
	}

	void Rectangle::draw(ostream& os)const {
		if (m_width && m_height) {
			//First Line
			cout << "+";
			for (unsigned i = 0; i < (m_width - 2); i++) {
				cout << "-";
			}
			cout << "+"<<endl;

			//Second line
			cout << "|";
			cout << setw(m_width - 2) << left << label() << "|" << endl;

			//Third Line //Fourth Line
			
			for (unsigned m = 3; m <= m_height - 1; m++) {
				cout << "|";
				for (unsigned k = 0; k < m_width - 2; k++) {
					cout << " ";
				}
				cout << "|" << endl;
			}

			//Last line
			cout << "+";
			for (unsigned j = 0; j < m_width - 2; j++) {
				cout << "-";
			}
			cout << "+";


		}
	}

}
