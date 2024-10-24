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
#ifndef RECTANGLE_H
#define RECTANGE_H
#include "LblShape.h"
namespace seneca {
	class Rectangle:public LblShape {
		unsigned  m_width{};
		unsigned  m_height{};
	public:
		Rectangle();
		Rectangle(const char* value, int height, int width);
		//~Rectangle()=default;
		void getSpecs(std::istream& is);
		void draw(std::ostream& os)const;

	};
}

#endif
