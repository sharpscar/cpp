#include <iostream>
int main(){
    using namespace std;
    double *p3 = new double[3];
    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;

    cout <<"p3[1]은 " <<p3[1] << "입니다. \n";
    p3= p3 +1; //포인터를 증가시킨다.
    cout << "이제는 p3[0]이 " << p3[0] << "이고, ";
    cout << "p3[1]이 " <<p3[1] << "입니다. \n";

    p3 = p3 -1; //다시 시작위치를 지시한다.
    delete [] p3;





    return 0;
}