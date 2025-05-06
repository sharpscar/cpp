#include <iostream>
#include <string>
#include <cstring>

int main(){
    using namespace std;
    char charr1[20];
    char charr2[20]="jaguar";
    string str1;
    string str2 = "panther";

    //string 객체의 대입과 문자 배열의 대입
    str1 = str2;

    strcpy(charr1, charr2);
    //string 객체의 추가와 문자 배열의 추가
    str1 += " paste";
    strcat(charr1, " juice");

    //string 객체의 길이 구하기와 c 스타일 문자열의 길이 구하기
    int len1 = str1.size();
    int len2 = strlen(charr1);

    cout << str1 <<"문자열 에는"
        <<len1 <<"개의 문자가 들어있다. \n";
        
    cout << charr1 << "문자열에는 " 
        <<len2 <<"개의 문자가 들어있다. \n";

    return 0;
}