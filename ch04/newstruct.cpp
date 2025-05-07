#include <iostream>
struct inflatable{
    char name[20];
    float volume;
    double price;
};

int main(){
    using namespace std;

    inflatable *ps = new inflatable;

    cout <<"모형풍선의 이름을 입력하십시오 : ";
    cin.get(ps->name, 20);
    cout << "부피를 세제곱 피트단위로 입력하십시오: ";
    cin >> (*ps).volume;
    cout<< "가격을 달러단위로 입력하십시오: $ ";
    cin >> ps->price;
    cout << "이름 : " <<(*ps).name << endl;
    cout << "부피 : " <<ps->volume << " cubic feet\n";
    cout << "가격 : " <<ps->price << endl;
}