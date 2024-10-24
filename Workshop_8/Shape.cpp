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
#include "Shape.h"
namespace seneca {


	ostream& operator<<(ostream& os, const Shape& s) {
		s.draw(os);
		return os;
	}

	istream& operator>>(istream& is, Shape& s) {
		s.getSpecs(is);
		return is;
	}
}
