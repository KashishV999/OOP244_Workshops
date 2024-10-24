#ifndef SENECA_HTMLTEXT_H__
#define SENECA_HTMLTEXT_H__
#include "Text.h"
namespace seneca {
    //if anything goes wrong in setting up the class or reading a file, it will be set to an empty state.
    class HtmlText : public Text {
        char* m_title{};
    public:

        HtmlText(const char* filename = nullptr, const char* title = nullptr);
        HtmlText(const HtmlText& other);
        HtmlText& operator=(const HtmlText& other);
        void write(std::ostream& os)const;
        ~HtmlText();

    };
}
#endif // !SENECA_HTMLTEXT_H__




