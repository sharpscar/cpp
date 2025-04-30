#include <iostream>
#include "./account.h"


Account:: Account(){
    
    std::string name = "박경태";
    std::string account_number = "1002-451-500126";
    balance = 0.0;


};


Account:: Account(const std::string &name,const std::string &account_number, double balance=0.0){
    
}

Account :: ~Account(){

}

void Account::show_account(){
    using std::cout;
    cout << "현재 잔고 :" << this->balance;
}

void Account:: deposit_money(double money){
    this->balance = this->balance + money;
}

void Account :: withdrawal_money(double money){
    this->balance = this->balance - money;
}