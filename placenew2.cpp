#include <iostream>
#include <string>
#include <new>

using namespace std;
const int BUF = 512;

class JustTesting{
    private:
        string words;
        int number;

    public:
        JustTesting(const string &s = "Just Testing", int n=0){
            words = s;
            number= n;
            cout << words <<"생성 \n";
        }
        ~JustTesting() {
            cout<< words <<" 파괴\n";
        }
        void Show() const{
            cout<< words <<", " << number << endl;
        }
};

int main(){
    //메모리 블록을 얻는다.
    char *buffer = new char[BUF];

    JustTesting *pc1, *pc2;

    //객체를 버퍼에 놓는다.
    pc1 = new (buffer ) JustTesting;
    // 객체를 힙에 놓는다.
    pc2 = new JustTesting("Heap1", 20);

    cout << "메모리 블록 주소 : \n" << "buffer : "
    <<(void *) buffer << "  heap: " <<pc2 << endl;

    cout << "메모리 내용: \n";
    cout << pc1 << " : " ; //포인터기때문에 0x14f605f50 메모리의 번지수가 나옴
    pc1->Show();            //객체의 내용은 문자열, int
    cout<< pc2 <<" : ";     //마찬가지
    pc2->Show();
    JustTesting *pc3, *pc4;

    pc3 = new (buffer + sizeof(JustTesting)) JustTesting ("Bad Idea", 6);
    pc4 = new JustTesting("Heap2", 10);

    cout <<"메모리 내용 : \n";
    cout << pc3 << " : ";
    pc3 ->Show();
    cout <<pc4 <<" :" ;
    pc4 ->Show();

    delete pc2;
    delete pc4;

    pc3->~JustTesting();
    pc1->~JustTesting();
    delete [] buffer;
    cout << "종료\n";
    return 0;

}