#include <iostream>
using std::cout;
#include "./stonewt.cpp"

void display(const Stonewt &st, int n);

int main(){

    Stonewt pavarotti =275;  //생성자로 초기화함

    Stonewt wolfe(285.7);
    Stonewt taft(21, 8);

    cout << "테너 가수의 몸무게 :";
    pavarotti.show_stn();
    cout << "탐정의 몸무게 :";
    wolfe.show_stn();
    cout << "대통령의 몸무게 :";
    taft.show_lbs();
    pavarotti = 276.8;
    taft =325;
    cout << "저녁식사를 마친 후 테너 가수의 몸무게: ";
    pavarotti.show_stn();

    cout << "저녁식사를 마친 후  대통령의 몸무게: ";
    taft.show_stn();
    display(taft, 2);
    cout << "레슬링 선수는 그보다 더 무겁다. \n";

    display(422,2);
    cout << "비만은 건강의 최대 적이다. \n";
    

    return 0;
}

void display(const Stonewt & st, int n){
    for (int i =0; i< n; i++){
        cout<< "와! " ;
        st.show_stn();
    }
}
