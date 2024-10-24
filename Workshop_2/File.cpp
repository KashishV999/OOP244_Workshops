/*/////////////////////////////////////////////////////////////////////////
Full Name  :Kashish Verma
Student ID#:151579232
Email      :kverma45@myseneca.ca
Date       :25 May 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace seneca{
    FILE* fptr;
   bool openFile(const char filename[]) {
     
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   

   bool read(char* emp_name) {
       return fscanf(fptr, "%[^\n]\n", emp_name) == 1;
   }

   bool read(int& emp_number) {
       return fscanf(fptr, "%d,", &emp_number) ==1;
   }

   bool read(double& emp_salary) {
       return fscanf(fptr, "%lf,", &emp_salary) == 1;
   }

}
