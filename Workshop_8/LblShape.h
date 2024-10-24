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
#ifndef LBLSHAPE_H
#define LBLSHAPE_H
#include "Shape.h"
namespace seneca{
	class LblShape:public Shape {
		char* m_label{};
	protected:
		const  char *label()const;
	public:
		LblShape() = default;
		LblShape(const char* label);
		virtual ~LblShape();

		LblShape(const LblShape& other) = delete;
		LblShape& operator=(const LblShape& other) = delete;
		void getSpecs(istream& is);
		virtual void draw(ostream& os)const = 0;
	};
}

#endif
