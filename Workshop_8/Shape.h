/*/////////////////////////////////////////////////////////////////////////
Full Name  :Kashish Verma
Student ID#:151579232
Email      :kverma45@myseneca.ca
Date       :20 July  2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/


#pragma once
#ifndef SHAPE_H
#define SHAPE_H
using namespace std;
#include <iostream>
namespace seneca {
	class Shape {
	public:
		virtual void draw(ostream& os)const=0;
		virtual void getSpecs(istream& is) = 0;
		virtual ~Shape()=default;
	};

	ostream& operator<<(ostream &os, const Shape& s);
	istream& operator>>(istream& is, Shape& s);
}

#endif
