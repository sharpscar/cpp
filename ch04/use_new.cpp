#include <iostream> 
int main(){
    using namespace std;
    int nights = 1001;
    int *pt = new int; //int형을 저장할 메모리를 대입
    *pt =1001; //대입된 메모리에 값을 저장

    cout << "nights 의 값 = " ;
    cout << nights << ": 메모리의 위치 " <<&nights<< endl;
    cout << "int형 ";
    cout <<"값 = " << *pt << " : 메모리의 위치 = " << pt << endl;
    
    double * pd = new double ; 
    *pd = 10000001.0;

    cout <<"double 형";
    cout <<" 값 = " << *pd << ": 메모리의 위치 = " << pt << endl;
    cout << "포인터 pd의 메모리 위치: " <<  &pd << endl;
    cout <<"pt의 크기 = " << sizeof(pt);
    cout <<" : *pt의 크기=" << sizeof(*pt) << endl;
    cout << "pd의 크기 = " << sizeof pd;
    cout << ": *pd의 크기 = " << sizeof(*pd) << endl;
    return 0;
}