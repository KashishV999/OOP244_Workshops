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
#ifndef LINE_H
#define LINE_H
#include "LblShape.h"
namespace seneca {
	class Line :public LblShape {
		int m_length{};
	public:
		Line();
		Line(const char* value, int length);
		//~Line()=default;
		void getSpecs(std::istream& is);
		void draw(std:: ostream& os)const;
	};
}

#endif
