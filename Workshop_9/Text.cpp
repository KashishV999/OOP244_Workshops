#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include "Text.h"
using namespace std;
namespace seneca {
    int Text::getFileLength() const {
        int len = 0;
        ifstream fin(m_filename);
        while (fin) {
            fin.get();
            len += !!fin;
        }
        return len;
    }


    Text::Text(const char* filename) {
        if (filename) {
            delete[] m_filename;
            m_filename = nullptr;
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);

            read();
        }
    }


    Text::~Text() {
        delete[]m_filename;
        m_filename = nullptr;

        delete[] m_content;
        m_content = nullptr;
    }



    Text::Text(const Text& other) {
        if (other.m_filename && other.m_content) {

            m_filename = new char[strlen(other.m_filename) + 1];
            strcpy(m_filename, other.m_filename);

            m_content = new char[strlen(other.m_content) + 1];
            strcpy(m_content, other.m_content);
        }
    }


    Text& Text:: operator=(const Text& other) {
        if (this != &other && other.m_filename && other.m_content) {
            delete[]m_filename;
            m_filename = nullptr;
            m_filename = new char[strlen(other.m_filename) + 1];
            strcpy(m_filename, other.m_filename);

            delete[] m_content;
            m_content = nullptr;
            m_content = new char[strlen(other.m_content) + 1];
            strcpy(m_content, other.m_content);
        }
        return *this;
    }

    void Text::write(std::ostream& os)const {
        if (m_content) {
            os << m_content;
        }
    }

    //not defined if the index goes out of bounds.
    const char& Text:: operator[](int index)const {
        return m_content[index];
    }


    std::ostream& operator<<(std::ostream& os, const Text& other)
    {
        other.write(os);
        return os;
    }

    //This will read the content of file with the name m_filename
    // and store that content into m_content 
    void Text::read() {
        //read will the current content of the file
        ifstream inputfile(m_filename);
        if (!inputfile) {
            cout << "ERROR READING CONTENT OF FILE";
        }
        else {
            delete[]m_content;
            m_content = nullptr;
            m_content = new char[getFileLength() + 1];

            char c{};
            int index = 0;
            while (inputfile.get(c)) {
                m_content[index] = c;
                index++;
            }
            m_content[index] = '\0';
        }

    }

}


/*
To allocate memory dynamically to hold the content of a file on the disk in C++, you need to follow these steps:

Open the file.
Determine the size of the file.
Allocate a buffer of appropriate size.
Read the file content into the buffer.
Close the file.
*/