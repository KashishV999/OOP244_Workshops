/*/////////////////////////////////////////////////////////////////////////
Full Name  :Kashish Verma
Student ID#:151579232
Email      :kverma45@myseneca.ca
Date       :25 May 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/


#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_

namespace seneca {
	
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare read prototypes
   bool read(char *emp_name);
   bool read(int &emp_number);
   bool read(double &emp_salary);

}
#endif // !SENECA_FILE_H_
