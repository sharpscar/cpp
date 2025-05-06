#include <iostream>
#include "./mytime0.h"

Time::Time(){
    hours = minutes = 0;
}

Time::Time(int h, int m){
    hours = h;
    minutes = m;
}

void Time::AddMin(int m){
    minutes +=m;
    hours +=minutes /60;
    minutes %= 60; 
}

void Time::AddHr(int h){
    hours += h;
}

void Time::Reset(int h, int m ){
    hours = h;
    minutes = m;
}

/* 시간을 받아서 시간을 리턴
    분을 더함
    시간을 더함
    다시분의 나머지를 계산
*/
Time Time::Sum(const Time &t) const{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes /60;
    sum.minutes %= 60;
    return sum;
}

void Time::Show() const {
    std::cout << hours << "시간, " <<minutes <<"분";
}