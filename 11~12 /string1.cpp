#include <cstring>
#include "./string1.h"

using std::cin;
using std::cout;

int String::num_strings =0;

int String::HowMany(){
    return num_strings;
}

String ::String(const char *s){
    len = std::strlen(s); //문자열의 크기를 설정한다.
    str = new char[len+1];// 기억공간을 대입한다.
    std::strcpy(str, s); //포인터를 초기화한다.
    num_strings++; //객체 카운트 설정

}

String::String () //디폴트 생성자
{
    len =4;
    str = new char[1];
    str[0] = '\0'; //디폴트 문자열
    num_strings++;
}

String::String(const String &st){
    num_strings++;  //static 멤버 갱신을 처리한다.
    len = st.len;   //같은크기로 설정한다.
    str = new char[len+1]; //기억공간을 대입한다.
    std::strcpy(str, st.str); //문자열을 새위치에 복사한다.
}

String::~String(){
    --num_strings;
    delete []str;
}


//오버로드 연산자 메서드

//String을 String에 대입한다.
String &String::operator=(const String &st){
    if(this==&st)
        return *this;
    delete []str;
    len=st.len;
    str = new char[len+1];
    std::strcpy(str, st.str);
    return *this;
}

// c스타일의 문자열을 String에 대입한다. 
String &String::operator=(const char *s){
    delete [] str;
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str, s);
    return  *this;
}

// const가 아닌 String에 읽기-쓰기 개별 문자 접근
char &String::operator[](int i){
    return str[i];
}

//const String에 읽기 전용 개별 문자 접근
const char &String::operator[](int i) const{
    return str[i];
}


//오버로드 연산자 프렌드
bool operator<(const String & st1, const String & st2){
    return (std::strcmp(st1.str, st2.str)<0);
}
bool operator>(const String & st1, const String & st2){
    return st2 < st1;
}

bool operator==(const String & st1, const String & st2){
    return (std::strcmp(st1.str, st2.str)==0);
}

// 간단한 문자열 출력
ostream &operator << (ostream & os, const String &st){
    os<< st.str;
    return os;
}

istream & operator >>(istream &is, String &st){
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if(is)
        st=temp;
    while(is && is.get() != '\n')
        continue;

    return is;

}