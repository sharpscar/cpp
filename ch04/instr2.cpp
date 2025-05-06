#include <iostream>

int main(){
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout<<"이름을 입력하십시오:\n";
    cin.getline(name, ArSize); //개행문자가 있는곳까지 읽는다.
    cout<<"좋아하는 디저트를 입력하십시오\n";
    cin.getline(dessert, ArSize);
    cout <<" 맛있는 " <<dessert;
    cout <<" 디저트를 준비하겠습니다. " << name << "님!\n";
    return 0;

}