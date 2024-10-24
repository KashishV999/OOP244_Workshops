/*/////////////////////////////////////////////////////////////////////////
Full Name  :Kashish Verma
Student ID#:151579232
Email      :kverma45@myseneca.ca
Date       :06 July 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TextFile.h"
using namespace std;
namespace seneca {
    //return line
   Line::operator const char* () const {
      return (const char*)m_value;
   }

   //assign
   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strlen(lineValue) + 1];
      strcpy(m_value, lineValue);
      return *this;
   }
   Line::~Line() {
      delete[] m_value;
   }

  
   void TextFile::setEmpty() {

       if (m_filename != nullptr) {
           delete[] m_filename;
           m_filename = nullptr;
       }

       if (m_textLines != nullptr) {
           delete[] m_textLines;
           m_textLines = nullptr;
       }

       m_noOfLines = 0;
   }

   

   

   void TextFile::setFilename(const char* fname, bool isCopy) {
       if (fname) {

          
               delete[] m_filename;
                m_filename = nullptr;
          

          
               if (isCopy == false) {
                   m_filename = new char[strlen(fname) + 1];
                   strcpy(m_filename, fname);
               }

               else {
                   m_filename = new char[strlen("C_") + strlen(fname) + 1];
                   strcpy(m_filename, "C_");
                   strcat(m_filename, fname);

               }
           
       }
   }
    
   
   void TextFile::setNoOfLines() {
       ifstream file(m_filename);
       if (file) {
           char c{};
           char lastc{};
           m_noOfLines = 0;

           while (file.get(c)) {
               lastc = c;
               if (c == '\n') {
                   m_noOfLines++;
               }
           }

           if (lastc != '\n') {
               m_noOfLines += 1;
           }

           if (m_noOfLines == 0) {
               setEmpty();
           }
       }
   }
   
   

   void TextFile::loadText() {
       ifstream file(m_filename);
       if (file) {
           delete[] m_textLines;
           m_textLines = nullptr;
           m_textLines = new Line[m_noOfLines];
           string line;
           unsigned i = 0;
           while (getline(file, line) && i < m_noOfLines) {
               m_textLines[i] = line.c_str();
               i++;

           }
           m_noOfLines = i;
       }
       else {
           return;

       }
   }

   void TextFile::saveAs(const char* filename)const {
       ofstream file(filename);
      
          
           for (unsigned i = 0; i < m_noOfLines; i++)
           {
               file << m_textLines[i] << endl;
               
           }
       
   }


//Type Conversion Operator
   TextFile:: operator bool()const {
       return m_textLines && m_filename && (m_noOfLines > 0);
   }
   const char* TextFile::name()const {
       return m_filename;

   }

   unsigned TextFile:: lines()const {
       return m_noOfLines;
   }

   //Extraction and insertion
  ostream& operator<<(ostream& ostr, const TextFile& text) {
      
          return text.view(ostr);
     
 
   }
  istream& operator>>(istream& istr, TextFile& text) {
      return text.getFile(istr);
  }

  const char* TextFile:: operator[](unsigned index)const {
    
      if (*this) {
          if (index < m_noOfLines) {
               return m_textLines[index] ;
             
          }
          else {
              return m_textLines[index-m_noOfLines];
             
          }
      }

return nullptr;
  }

  ostream& TextFile:: view(ostream& ostr)const {
      if(*this){
          ostr << name() << endl;
          for (unsigned i = 0; i < strlen(name()); i++)
          {
              ostr << "=";
          }
          ostr << endl;
          unsigned count = 0;
          for (unsigned i = 0; i < m_noOfLines; i++) {
              ostr << (*this)[i] << endl;
              count++;
              char c;
              while (count == m_pageSize) {

                  cout << "Hit ENTER to continue...";

                    cin.get(c);
                    if (c == '\n') {
                        count = 0;
                       
                        cin.clear();
                    }
                    else {
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }

              }
          }
         
      }
      return ostr;
}





  istream& TextFile::getFile(istream& istr) {
      string name{};
      istr >> name;
     


      if (istr.fail()) {
          istr.clear();
          istr.ignore(1000, '\n');

      }
      else {

          setFilename(name.c_str());
          setNoOfLines();
          loadText();
      }
      istr.clear();
      istr.ignore(1000, '\n');
      return istr;
  }




  TextFile::TextFile(unsigned pageSize) {
      setEmpty();
      m_pageSize = pageSize;  
  }

  TextFile::TextFile(const char* filename, unsigned pageSize) {
      setEmpty();
      m_pageSize = pageSize;
      if (filename) {
          m_filename = new char[strlen(filename) + 1];
          strcpy(m_filename, filename);
          setNoOfLines();
          loadText();
      }     
  }


  TextFile::TextFile(const TextFile& other) {

      m_pageSize = other.m_pageSize;
      setEmpty();
      
  

      if ((other.m_filename) && other.m_noOfLines > 0 && (other.m_textLines)) {
          setFilename(other.m_filename, true);

          other.saveAs(m_filename);
          setNoOfLines();
          loadText();

      }

  }

  TextFile& TextFile:: operator=(const TextFile& other) {
      if (this != &other) {
          if ((other.m_filename) && other.m_noOfLines > 0 && (other.m_textLines)) {
              m_pageSize = other.m_pageSize;
              delete[]m_textLines;
              m_textLines = nullptr;
              other.saveAs(m_filename);
           setNoOfLines();
              loadText(); 
               
          }
      }
      return *this;
  }

  TextFile::~TextFile() {
      delete[]m_filename;
      m_filename = nullptr;
      delete[]m_textLines;
      m_textLines = nullptr;
  }



}
