#include <iostream>

int main(){
    using namespace std;
    int updates = 6;
    int *p_updates;

    p_updates = &updates;


    cout << "값: updates = " << updates;
    cout << ", *p_updates = "<< *p_updates << endl;

    //주소를 두가지 방법으로 표현
    cout << " 주소:  &updates = " << &updates;
    cout << ", p_updates = "  <<  p_updates << endl;

    //포인터를 사용하여 값을 변경
    *p_updates = *p_updates+1;
    cout << "변경된 updates = " << updates << endl;
    return 0;
}