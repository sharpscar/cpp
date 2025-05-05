#include <iostream>
#include "./mytime1.h"
#include "./mytime1.cpp"

int main(){
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2, 40);
    Time fixing(5,55);
    Time total;


    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = " ;
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    /* 객체 + 객체가 된다고? */
    total = coding + fixing ;
    cout << "coding.Sum(fixing) = ";
    total.Show();
    cout << endl;

    Time morefixing(3, 28);
    cout << "more fixing time = ";
    morefixing.Show();
    cout <<endl;

    /* 여기선 또 객체에 . 으로 접근한다고? */
    total = morefixing.operator+ (total);

    //함수표기
    cout << "morefixing.operator+ (total) = ";
    total.Show();
    cout << endl;


    return 0;


}