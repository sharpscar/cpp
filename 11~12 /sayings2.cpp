#include <iostream>
#include <cstdlib>
#include <ctime>
#include "./string1.cpp"



const int ArSize = 10;
const int MaxLen = 81;

int main(){
    using namespace std;    
    
    
    String name;

    cout << "안녕하십니까? 성함이 어떻게 되십니까? \n>> ";
    cin >> name;

    cout << name << " 씨! 간단한 영어속담 " << ArSize
    << "개만 입력해주십시오 (끝내려면 Enter ) : \n " ;
    String sayings[ArSize];
    char temp[MaxLen];
    int i;

    for(i=0; i< ArSize; i++ ){
        cout << i+1 << ": ";
        cin.get(temp, MaxLen);
        while(cin && cin.get() != '\n')
            continue;
        if(!cin || temp[0] == '\0')
            break;
        else
            sayings[i] = temp;
    }

    int total = i;
    if(total >0){
        cout << "(다음과 같은 속담들을 입력하셨습니다. )\n";
        for(i =0 ; i< total ; i++)
        {
            cout << sayings[i] << "\n";
        }

        // 가장 짧은 문자열과, 사전순으로 가장 앞에 나오는 문자열을 추적하는 포인터
        String * shortest = &sayings[0];
        String *first = &sayings[0];
        for (i =1; i<total; i++){
            if(sayings[i].length() < shortest->length()) //가장짧은 문자열을 찾아서
                shortest = &sayings[i];                 // shortest 객체에 대입
            if(sayings[i]< *first)    //값들을 비교한다
                first = &sayings[i];  //주소를 대입
        }
        cout <<"가장짧은 속담 : \n" << *shortest << endl;
        cout <<"사전순으로 가장 앞에 나오는 속담 : \n" << *first << endl;
        srand(time(0));
        int choice = rand() % total; //배열 인덱스를 무작위로 선택한다. 

        //new를 사용하여 새로운 String 객체를 생성하고 초기화한다.
        String *favorite = new String(sayings[choice]);
        cout << "내가 가장 좋아하는 속담 : \n" << *favorite << endl;
        delete favorite;
    }
    else
        cout <<" 알고있는 속담이 하나도 없어요? \n";
    cout <<"프로그램을 종료합니다. \n";
    
    return 0;

}