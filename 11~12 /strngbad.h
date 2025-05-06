#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_

class StringBad{
    private:
        char *str;               // 문자열을 지시하는 포인터 
        int len;                //문자열의 길이
        static int num_strings; //객체의수

    public:
        StringBad(const char *s);
        StringBad();
        ~StringBad();


    friend 
        std::ostream &operator << (std::ostream &os, const StringBad &st);
};



#endif