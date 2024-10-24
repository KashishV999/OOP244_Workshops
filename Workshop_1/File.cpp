/*/////////////////////////////////////////////////////////////////////////
Full Name  :Kashish Verma
Student ID#:151579232
Email      :kverma45@myseneca.ca
Date       :17 May 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor 
provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio> 
#include<iostream>
#include "File.h"
#include "Utils.h"
#include "ShoppingList.h"

using namespace std;

FILE* sfptr = nullptr;

namespace seneca {

	const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";
	bool openFileForRead() {
		sfptr = fopen(SHOPPING_DATA_FILE, "r");
		return sfptr != NULL;
	}

	bool openFileForOverwrite() {
		sfptr = fopen(SHOPPING_DATA_FILE, "w");
		return sfptr != NULL;
	}

	void closeFile() {
		if (sfptr) fclose(sfptr);
	}

	bool freadShoppingRec(ShoppingRec* rec) 
	{
		int flag = 0;
		bool success = fscanf(sfptr, "%[^,],%d,%d\n",
			rec->m_title, &rec->m_quantity, &flag) == 3;
		rec->m_bought = !!flag;
		return success;
	}

	void fwriteShoppintRec(const ShoppingRec* rec) {
		fprintf(sfptr, "%s,%d,%d\n", rec->m_title, rec->m_quantity, rec->m_bought);
	}



}
