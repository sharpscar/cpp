#include <iostream>
#include "./account.h"
#include "./account.cpp"

int main(){

    Account my_account = Account("박경태","1002-451-500126",1500000.0);

    my_account.show_account();

    return 0;
}