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
#include <iostream>
#include <cstring>
#include <cstdio>

#include "Employee.h"
#include "File.h"

using namespace std;
namespace seneca {

    int noOfEmployees;
    Employee* employees;

    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    
    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
	    /* if reading of employee number, salay and name are successful
            allocate memory to the size of the name + 1
            and keep its address in the name of the Employee Reference
            copy the name into the newly allocated memroy
            make sure the "ok" flag is set to true
           end if
           */
    bool load(Employee& emp) {
        bool ok = false;
        char name[128];
      
            if (read(emp.m_empNo) && read(emp.m_salary) && read(name)) {
                emp.m_name = new char[strlen(name) + 1];
                strcpy(emp.m_name, name);
                ok = true;
            }
      
       
    
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
    
        return ok;
    }
    
    
    // TODO: Finish the implementation of the 0 arg load function 
    bool load() {
        bool ok = false;
        
        int count = 0;
        if (openFile(DATAFILE)) {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            
            for (int i = 0; i < noOfEmployees; i++)
            {
                // 'i' is the count to check that the file is read correctly
                count += load(employees[i]);
            }

            // If the number of the records does not match the number of reads print the message
            if (count != noOfEmployees)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            else
            {
                ok = true;
            }

            closeFile();
        }

        
    
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        
        return ok;
     
    }
    






    // TODO: Implementation for the display functions go here
    //NUMBER: NAME, SALARY<NEWLINE>
    void display(const Employee& employee) {
        cout << employee.m_empNo << ": " << employee.m_name << ", " << employee.m_salary << endl;
    }

    void display() {
        cout << "Employee Salary report, sorted by employee number" << endl
            << "no- Empno, Name, Salary" << endl
            << "------------------------------------------------" << endl;
        sort();
        for (int i = 0; i < noOfEmployees; i++)
        {
            //IDX- NUMBER: NAME, SALARY<NEWLINE>
            cout << i + 1 << "- ";
             display(employees[i]);
        }
    }


    // TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory() {
        for (int i = 0; i < noOfEmployees; i++)
        {
            delete[] employees[i].m_name;
        }
        delete[] employees;
        employees = nullptr;
        noOfEmployees = 0;
    }
}
  
