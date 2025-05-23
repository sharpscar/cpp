#include <iostream>
#include "./stock00.h"

void Stock::acquire(const std::string &co, long n , double pr){
    company = co;
    
    //입력된 매개변수가 음수일경우 예외처리한다.
    if(n<0){
        std::cout <<"주식 수는 음수가 될수 없으므로, "
            <<company << "shares를 0으로 설정합니다. \n";
        shares = 0;
    }

    else 
        shares = n;
    share_val = pr;
    set_tot();

}
void Stock::buy(long num, double price){
    if(num<0)
    {
        std::cout << "입 주식수는 음수가 될수 없으므로, "
        <<"거래가 취소되었습니다. \n";
    }else{
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price){
    using std::cout;
    if(num<0){
        cout << "매도 주식수는 음수가 될 수 없으므로, "
        <<" 거래가 취소되었습니다. \n";
    }else if(num > shares){
        cout << "보유 주식 보다 많은 주식을 매도할 수 없으므로 , "
        <<"거래가 취소되었습니다.\n";
    }
    else{
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price){
    share_val = price;
    set_tot();
}

void Stock::show(){
    std::cout << "회사명: " <<company
    <<" 주식 수: " << shares << '\n'
    <<" 주가 : $ "<< share_val
    <<" 주식 총 가치 : $" << total_val << '\n'; 
}