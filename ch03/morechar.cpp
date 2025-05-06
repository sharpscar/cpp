#include <iostream>

int main(){
    using namespace std;
    char ch = 'M';
    int i = ch;
    cout << ch <<"의 ascii 코드는"<< i <<"입니다. "<< endl;

    cout << "이 문자 코드에 1을 더해보겠습니다. "<<endl;
    ch = ch+1;
    i = ch;
    cout<< ch <<"의 ascii코드는 " <<i <<"입니다."<<endl;

    cout << "cout.put(ch)를 사용하여 캐릭터형 변수 ch를 화면에 출력: ";
    cout.put(ch);

    cout.put('!');

    cout << endl << "종료" <<endl;
    return 0;
    
}