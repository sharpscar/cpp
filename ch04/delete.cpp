#include <iostream>
#include <cstring>
using namespace std;
char * getname(void);
int main(){
    char *name;
    name = getname();
    cout << (int *) name<< ": " << name << "\n";
    delete [] name;

    name = getname(); //해제된 메모리를 다시 사용한다.
    cout <<  (int *) name <<": " << name << "\n";
    delete [] name;
    return 0;

}

char * getname(){ // 새 문자열을 가리키는 포인터를 리턴한다.
    char temp[80]; //임시배열
    cout << "이름을 입력하십시오 : ";
    cin >> temp;            //템프에 입력받고
    char * pn = new char [strlen(temp) +1]; // 새로운 문자열 81크기의 메모리 공간을 배정받는다.
    strcpy(pn, temp); // 배정받은 메모리 공간에 입력받은 문자열을 복사
    cout << "getname함수내에서 뿌리는 주소"<< (int*)pn<< "\n";
    return pn;

}