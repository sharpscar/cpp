#ifndef STRING1_H_
#define STRING1_H_
#include <iostream>

using std::ostream;
using std::istream;

class String{
    private:
        char *str;
        int len;
        static int num_strings;

    public :
    static const int CINLIM = 80;

    // 생성자와 기타 메서드
    String(const char *s);
    String();
    String(const String &st);
    ~String();
    int length() const {return len;}

    //오버로딩 연산자 메서드
    String &operator=(const String &st);
    String &operator=(const char *s);
    char &operator[] (int i);
    const char &operator[](int i) const;

    //오버로딩 연산자 프랜드
    friend bool operator<(const String &st1, const String &st);
    friend bool operator>(const String &st1, const String &st);
    friend bool operator==(const String &st1, const String &st);
    friend ostream &operator<<(ostream &os, const String &st);
    friend ostream &operator>>(ostream &os, const String &st);

    //static 함수
    static int HowMany();
};


#endif