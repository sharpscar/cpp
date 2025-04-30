#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>




class Account{
    private :
        std::string name[100];
        std::string account_number[50];
        double balance;

    public :
        Account();
        Account(const std::string &name,const std::string &account_number, double balance=0.0);
        void show_account();
        void deposit_money(double balance);
        void withdrawal_money(double balance);



};


#endif