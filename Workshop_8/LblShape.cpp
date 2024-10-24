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
#include "LblShape.h"
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
 namespace seneca {
	const char* LblShape::label()const {
		 return m_label;
	 }

	 LblShape:: LblShape(const char* label) {
		 if (label) {
			 m_label = new char[strlen(label)+1];
			 strcpy(m_label, label);
		 }
	 }

	 LblShape::~LblShape() {
		 delete[] m_label;
		 m_label = nullptr;
	 }
	 void LblShape::getSpecs(istream& is)
	 {
		 string name;
		 getline(is, name, ',');
                 delete[] m_label;
		 m_label = new char[name.length() + 1];
		 strcpy(m_label, name.c_str());
	 }
}
