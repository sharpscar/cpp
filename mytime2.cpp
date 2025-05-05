#include <iostream>
#include "./mytime2.h"

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
Time Time::operator+(const Time &t) const{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes /60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-(const Time &t) const{
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;

    /* 도대체 어디서 가져오는  hours 냐? 혹시 객체를 생성할때 기본적으로 생성되는 멤버들인가?
    그럼 왜 this라는 키워드를 안썼을까?함수 내에서는 멤버는 그냥 이렇게 자연스럽게 접근이되는 녀석인가?
    */
    tot2 = minutes + 60 * hours;

    diff.minutes = (tot2 - tot1) %60;
    diff.hours = (tot2 - tot1) /60;
    return diff;
}

Time Time::operator*(double mult) const{
    Time result;
    long totalminutes = hours * mult * 60 + minutes * mult;
    result.hours = totalminutes /60;
    return result;
    
}

void Time::Show() const {
    std::cout << hours << "시간, " <<minutes <<"분";
}