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
#ifndef SHOPPING_REC
#define SHOPPING_REC

namespace seneca {
	
	const int MAX_TITLE_LENGTH = 50;
	const int MAX_QUANTITY_VALUE = 50;

	struct ShoppingRec {
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};

	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec* shp);
	void toggleBoughtFlag(ShoppingRec* rec);
	bool isShoppingRecEmpty(const ShoppingRec* shp);

}


#endif
