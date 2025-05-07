#include <iostream>
#include <cstring>

int main(){
    using namespace std;
    char animal[20] = "bear";   //animal에 bear가 들어있다.
    const char *bird = "wren"; // bird에 문자열의 주소가 들어있다.
    char * ps;

    cout << animal << " and " ;
    cout << bird << "\n";   //
    // cout << ps << "\n"; //쓰레기를 출력하거나 먹통이 될수 도 있다.

    cout << "동물의 종류를 입력하십시오: " ;
    cin >> animal;  //애니멀 문자열배열에 입력을받는다.
    // cin >> ps; 절대로 해서는 안될 엄청난 실수이다.
    //ps가 대입된 공간을 지시하고 있다.

    ps = animal;
    cout << "strcpy() 사용전: \n";
    cout << (int *) animal << " : " << animal << endl;
    cout << (int * ) ps << ": " << ps << endl;

    ps = new char [strlen(animal)+ 1]; // 새 메모리를 대입한다.
    strcpy(ps, animal);

    cout<<"strcpy() 사용후 : \n";
    cout << (int *) animal << " : " << animal << endl;
    cout << (int *) ps << " : " << ps << endl;
    delete [] ps;
  
  
  
    return 0;


}