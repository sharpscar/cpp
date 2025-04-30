#include <iostream>


using namespace std;

class Stock{
    private:
        int shares;
        char company[30];
        double share_val;
        double total_val;
        void set_tot(){
            total_val = shares * share_val;
        }

    public :
        void acquire(const char * co, long n , double pr);
        void buy(int num, double price);
        void sell(int num, double price);
        void update(double price);
        void show();
};