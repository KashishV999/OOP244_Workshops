#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include "HtmlText.h"
using namespace std;
namespace seneca {
	HtmlText::HtmlText(const char* filename, const char* title)
		:Text(filename)
	{
		if (title) {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
	}

	HtmlText::~HtmlText() {
		delete[] m_title;
		m_title = nullptr;
	}

	HtmlText::HtmlText(const HtmlText& other)
		:Text(other)
	{
		if (other.m_title) {
			m_title = new char[strlen(other.m_title) + 1];
			strcpy(m_title, other.m_title);
		}
	}

	HtmlText& HtmlText:: operator=(const HtmlText& other) {
		if (this != &other && other.m_title) {
			Text::operator=(other);
			delete[] m_title;
			m_title = nullptr;
			m_title = new char[strlen(other.m_title) + 1];
			strcpy(m_title, other.m_title);
		}
		return *this;
	}

	void HtmlText::write(std::ostream& os)const {
		bool multipleSpace = false;
		os << "<html><head><title>";
		if (m_title) {
			os << m_title;
		}
		else {
			os << "No Title";
		}

		os << "</title></head>\n<body>" << endl;

		if (m_title) {
			os << "<h1>" << m_title << "</h1>\n";
		}

		int i = 0;
		char c{};
		
		while (this->operator[](i) != '\0') {
			c = this->operator[](i);
			switch (c) {
			case ' ':
				if (multipleSpace) {
					os << "&nbsp;";
				}
				else {
					multipleSpace = true;
					os << " ";
				}
				break;

			case '<':
				os << "&lt;";
				multipleSpace = false;
				break;

			case '>':
				os << "&gt;";
				multipleSpace = false;
				break;

			case '\n':
				multipleSpace = false;
				os << "<br />\n";
				break;

			default:
				multipleSpace = false;
				os << this->operator[](i);
			}
			i++;
		}
		os << "</body>\n</html>";
	}

}

/*
*  if MS is true insert "&nbsp;"
	 otherwise set MS to true and then insert a space (' ')
switch(expression) {
  case x:
	// code block
	break;
  case y:
	// code block
	break;
  default:
	// code block
}
*/
