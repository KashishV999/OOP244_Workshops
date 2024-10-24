/*/////////////////////////////////////////////////////////////////////////
Full Name  :Kashish Verma
Student ID#:151579232
Email      :kverma45@myseneca.ca
Date       :01 June 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_ITEM_H_
#define SENECA_ITEM_H_
namespace seneca {
   class Item {
      char m_itemName[21]{};
      double m_price{};
      bool m_taxed{};
      void setName(const char* name); //sets the itemName member 
   public:
      void setEmpty();//price to 0.0 &  m_itemName to a blank string 
      void set(const char* name, double price, bool taxed); 
      double price()const;//Returns the m_price
      double tax()const;//Returns the product of m_price and 0.13 || it returns 0.0 if the m_taxed is false.
      bool isValid()const;//Returns true if the Item is not set to the empty state
      void display()const;//Prints an item i
    
   };
}

#endif // !SENECA_SUBJECT_H
