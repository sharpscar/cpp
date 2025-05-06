#include  <iostream>
using std::cout;
#include "./stonewt.h"

//double 형 값으로 Stonewt 객체를 생성한다.
Stonewt::Stonewt(double lbs){
    stone = int(lbs) /Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;

}

//int 형 값과 double형 값으로 Stonewt 객체를 생성한다.
Stonewt::Stonewt(int stn, double lbs){
    stone = int(lbs) /Lbs_per_stn; //정수 나눗셈
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt(){
    stone = pounds = pds_left =0;
}

Stonewt::~Stonewt(){} //파괴놈!

//무게를 스톤과 파운드의 조합 형식으로 출력
void Stonewt::show_stn() const{
    cout<<stone <<"스톤," <<pds_left<< "파운드\n";
}


//무게를 파운드 형식으로 출력한다.
void Stonewt::show_lbs() const{
    cout <<pounds <<"파운드 \n";
}


