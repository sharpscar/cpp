#include <iostream>
#include "./mytime2.h"
#include "./mytime2.cpp"

int main(){
    using std::cout;
    using std::endl;
    Time weeding(4, 35);
    Time waxing(2,47);
    Time total;
    Time diff;
    Time adjusted;



    cout << "weeding time = ";
    weeding.Show();
    cout << endl;

    cout << "waxing time = " ;
    waxing.Show();
    cout << endl;

    cout << "total work time = ";
    total = weeding + waxing;
    total.Show();
    cout << endl;

    diff = weeding - waxing;
    cout << "weeding time - waxing time = ";
    diff.Show();
    cout << endl;

    adjusted = total * 1.5;
    cout << "adjusted work time = ";
    adjusted.Show();
    cout <<endl;

   

    return 0;


}
/**
 * 결론 : 연산자 오버로딩은 이렇게 경우(필요)에 따라서는 편리하게 쓸수있다.
 * 어디에 쓰는물건인고? 객체연산을 보다 멋지게 처리하는 테크닉 
 * 
 * 우리가 신경써야 하는 부분은 프렌드가 아닌 벡터쪽일거같다는 느낌이 살살온다.
 * 
 */