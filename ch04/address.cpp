#include <iostream>

int main(){
    using namespace std;
    int donuts =6;
    double cups = 4.5;

    cout <<"donuts의 값 =" << donuts;
    cout <<", donuts의 주소 = " << & donuts << endl;

    cout <<" cpus의 값 = " << cups;
    cout <<" , cups의 주소 = " << &cups << endl;
    return 0;
}