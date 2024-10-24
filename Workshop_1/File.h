/*/////////////////////////////////////////////////////////////////////////
Full Name  :Kashish Verma
Student ID#:151579232
Email      :kverma45@myseneca.ca
Date       :17 May 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor 
provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#pragma once
#ifndef FILE_H
#define FILE_H
#include "ShoppingRec.h"
namespace seneca {
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);


}






#endif
