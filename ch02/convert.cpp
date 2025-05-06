#include <iostream>

int stonetolb(int);

int main(){
    using namespace std;
    int stone;
    cout << "체중을 스톤단위로 입력하시오 : ";
    cin >> stone;
    int pounds = stonetolb(stone);
    cout << stone << "스톤은 ";
    cout << pounds << "파운드 입니다. " << endl;
    return 0;
}

int stonetolb(int sts){
    return 14* sts;
}