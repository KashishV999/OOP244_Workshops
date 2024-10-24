#ifndef SENECA_TEXT_H__
#define SENECA_TEXT_H__
#include <cstring>
#include <iostream>
namespace seneca {
    //if anything goes wrong in setting up the class or reading a file, it will be set to an empty state.
    class Text {
        char* m_filename{};
        char* m_content{};
        int getFileLength()const;
    protected:
        const char& operator[](int index)const;
    public:

        Text(const char* filename = nullptr);
        ~Text();
        Text(const Text& other);
        Text& operator =(const Text& other);
        void read();
        virtual void write(std::ostream& os)const;


    };
    std::ostream& operator<<(std::ostream& os, const Text& other);
}
#endif // !SENECA_PERSON_H__



