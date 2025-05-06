#include <iostream>

class ExampleClass{
    public:
        int num;
        static int count; //클래스 변수

        ExampleClass(int num){
            count++;
            this->num = num;

        }
        void show_num(){
            std::cout<<this->num<< std::endl;

        }

        void set_num(int num){
            this->num = num;
        }

        int get_num(){
            return num;
        }
        
        ~ExampleClass(){  //파괴자
            count--;
        }
};

int ExampleClass::count = 0;

class ChildExampleClass: public ExampleClass{
    public:
        ChildExampleClass(int num): ExampleClass(num){}

        void show_num(){
            std::cout<< "자식클래스의 "<< this->num << std::endl;
        }
 

};

int main() {
    ExampleClass a = ExampleClass(10);
    ExampleClass b = ExampleClass(20);
    // std::cout << a.get_num << std::endl;
    // ChildExampleClass c = ChildExampleClass(30);

    // c.set_num(500);

    // a.show_num();
    // c.show_num();
    std::cout<< a.count << std::endl;
    
    std::cout<< b.count << std::endl;
    {
        
        ExampleClass c = ExampleClass(30);
        std::cout<< c.count << std::endl;
        
    }
    std::cout<< a.count << std::endl;


    return 0;
}
