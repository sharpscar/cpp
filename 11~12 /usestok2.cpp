#include <iostream>
#include "./stock20.h"
#include "./stock20.cpp"


const int STKS = 4;

int main()
{
    //초기화된 객체들의 배열을 생성한다.
    Stock stocks[STKS]={
        Stock("POSCO HOLDINGS", 13, 263000),
        Stock("POSCO DX", 298, 25150),
        Stock("LG chemical", 10, 111900),
        Stock("eco pro", 54, 51800),

    };

    std::cout << "보유 주식 리스트:\n";
    int st;
    for(st=0; st< STKS; st++)
        stocks[st].show();

    
    
    
    //첫번째 원소에 포인터  (배열의 첫번째 주소를 대입)
    const Stock *top = &stocks[0];
    for(st =1; st<STKS; st++)
        top = &top->topval(stocks[st]);
        
        
    //가장 가치 있는 주식의 최고치
    std::cout << "\n최고의 가치의 주식:\n";
    top->show();
    return 0;
}