#define RAPIDJSON_HAS_STDSTRING 1
#include "./game.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <ctime>
#include "./rapidjson_/document.h"
#include "./rapidjson_/writer.h"
#include "./rapidjson_/stringbuffer.h"
#include "./rapidjson_/istreamwrapper.h"

using namespace std;
using namespace rapidjson;

Game::Game(){

    srand(time(NULL));
    game_record = false;
    for (int i=0; i< 3; i++){
        com_num[i] = (rand() % 9 )+1;
        for(int j=0; j<i; j++)
            if(com_num[i] ==com_num[j]) 
            {
                i--;
                break;
            }
        cout<< "컴생성 난수[i]"<<com_num[i]<< endl;
    }

}
/**입력값 검증이 완벽하지는 않다. 경고메시지 수준 */
int*  Game::get_input_from_user(){
    //사용자로 부터 입력을 받아서  user_num 배열에 하나씩 할당!

    int not_good_flag = 1;
    int static input_num[3];
    int num=0;
    while(not_good_flag){

        cout << "첫번째 숫자를 입력하세요 : ";
        cin >>num;
        input_num[0] = num;
        cout << "두번째 숫자를 입력하세요 : ";
        cin >> num;
        input_num[1] = num;
        cout << "세번째 숫자를 입력하세요 : ";
        cin >>  num;
        input_num[2] = num;

        //입력된 배열에 중복된 요소가 없으면 재입력 not_good_flag =0;
        if(input_num[0]==input_num[1]|| input_num[1]==input_num[2]|| input_num[0]== input_num[2])
        {
            not_good_flag =1;
            cout<< "중복된 값을 입력하셨습니다. 집중하세요!\n\n"<<endl;
        }
        //입력된 배열에 0이하 10이상인 숫자가 있으면 재입력
        else if((input_num[0] <=0||input_num[0] >=10) ||(input_num[1] <=0||input_num[1] >=10) ||(input_num[2] <=0||input_num[2] >=10)){
            not_good_flag =1;
            cout<< "허용된 숫자가 아닙니다. 1~9까지만 입력! 집중하세요!\n\n"<<endl;
        }else{
            not_good_flag =0;
        }
        
        // if(num <=0||num >= 10 )
        // {
        //     cout<<"1~9사이 값을 입력해주세요"<<endl;
        //     cin>>num;
        // }
    }
    return input_num;

}
/** 
 * 이 안에서  비교판단한다.
 * com number와 user number가 위치와 값이 전부 동일하면 3스트라이크 라고 출력 하고 1을 리턴한다.
 * 위치는 다르지만 값이 동일하면 3볼 
 *
 */
int Game::compare_with_com_number(int * user_num){
    //컴퓨터 숫자와 유저 숫자를 가지고 비교 하여 int를 리턴하고 문자열을 출력하는 함수
    int strike=0;
    int ball =0;
    for (int i =0; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            if(com_num[i] == user_num[j] && i == j){
                strike++;
            }else if(com_num[i]== user_num[j] && i != j){
                ball++;
            }
        }
    }
    cout <<" strike is "<< strike << endl;
    cout <<" ball is "<< ball << endl;

    if (strike==3){
        cout <<" 3 strike! game over "<<  endl;
        print_gameover();

        game_record = true;
        return 1;
    }
    return 0;
}

void Game::record_to_file(int count_round){

    //  this->game_record  를 저장

    ofstream writeFile("record.txt" ,ios::app);

    if(!writeFile.is_open()){
        cerr<<"파일을 열수 없습니다." << endl;
        return;
    }

    string str;
    if(this->game_record){
        str = "승리하였습니다.";
    }else{
        str = "패배하였습니다.";
    }
    string stime = get_current_time();

    writeFile << "\n";
    writeFile << "게임 플레이한 시간 : "<< stime <<"\n";
    writeFile<< count_round << " 회차에 " <<  str << "\n";

    writeFile.close();
}
void Game::record_to_json_file(int count_round){

    string str;
    if(this->game_record){
        str = "승리하였습니다.";
    }else{
        str = "패배하였습니다.";
    }

    //Document 객체 생성
    rapidjson::Document document;
    document.SetObject();
    //할당자 확보
    rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
    
    // Value객체 생성(배열)
    rapidjson::Value arr(rapidjson::kArrayType);

    string stime = get_current_time();
    char *cp;
    
    
    Value key1("game_time", allocator);
    Value val1(stime,allocator);

    Value key2("record", allocator);
    Value val2(str, allocator);
    
    document.AddMember("게임 시간", val1, allocator);
    document.AddMember("게임 기록", val2, allocator);

    arr.PushBack(val1, allocator); // 숫자 추가
    arr.PushBack(val2, allocator); // 숫자 추가
    
    // document.AddMember("게임 시간",get_current_time(), allocator);
    // document.AddMember("게임 기록", str, allocator);

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

    document.Accept(writer);

    const char* jsonString = buffer.GetString();

    //json 파일쓰기 
    ofstream outputFile("./record.json",ios::app);
    outputFile << jsonString;
    outputFile.close();
    

}
void read_from_json_file(){
    ifstream readFile("record.json");
    if(!readFile.is_open()){
        cerr<<"파일을 열수 없습니다." << endl;
    }



    IStreamWrapper isw {readFile};

    Document doc{};
    doc.ParseStream(isw);

    StringBuffer buffer{};
    Writer<StringBuffer> writer{buffer};
    doc.Accept(writer);

    if(doc.HasParseError()){
        cout << "Error :" <<doc.GetParseError() << "\n" <<"Offset :"<< doc.GetErrorOffset() <<"\n";
        exit(1);
    }
    const string jsonStr {buffer.GetString()};
    cout<<jsonStr<<"\n";

    readFile.close();


}

void read_from_file(){
    ifstream readFile("record.txt");
    if(!readFile.is_open()){
        cerr<<"파일을 열수 없습니다." << endl;
    }
    string str;
    while(getline(readFile, str)){
        cout<< str<< endl;
    }
}
void Game::print_gameover(){
cout<<"    ⢶⣶⣶⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ "<<endl;
cout<<"⠀⠈⠉⠙⠛⠿⢷⣶⣤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
cout<<"⠀⠀⠀⠀⠀⠀⠀⣀⣬⣍⠛⠻⣿⣿⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
cout<<"⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣧⠈⣿⡿⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
cout<<"⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⠀⣿⣷⣌⣻⣿⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
cout<<"⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
cout<<"⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
cout<<"⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
cout<<"⠀⠀⠀⠀⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
cout<<"⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⡟⠀⠙⢿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀"<<endl;
cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣼⣿⣿⣿⣿⠃⠀⠀⠈⣿⣿⣿⣿⡀⠀⠀⠀⠀⠀⠀"<<endl;
cout<<"⠀⠀⠀⠀⢀⣠⣴⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠙⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀"<<endl;
cout<<"⠀⣤⣴⣾⣿⣿⣿⠿⠿⠛⠋⠉⠁⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣷⡀⠀⠀⠀⠀"<<endl;
cout<<"⠀⣿⣿⣿⠿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣷⡀⠀⠀⠀"<<endl;
cout<<"⠀⢻⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣶⣆⠀"<<endl;
cout<<"⠀⠀⠙⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠿⠿⠿⠿⡿⠿"<<endl;
}




void Game::print_gameover2(){
cout<<"    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀"<< endl;
cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠖⠚⠉⠁⠀⠀⠉⠙⠒⢄⠀⠀⠀⠀⠀⠀"<< endl;
cout<<"⠀⠀⠀⠀⠀⠀⠀⢀⠔⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⢢⡀⠀⠀⠀"<< endl;
cout<<"⠀⠀⠀⠀⠀⠀⡰⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣆⠀⠀"<< endl;
cout<<"⠀⠀⠀⠀⠀⢠⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢇⠀"<< endl;
cout<<"⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡄"<< endl;
cout<<"⠀⠀⠀⠀⢸⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠇"<< endl;
cout<<"⠀⠀⠀⠀⠸⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<< endl;
cout<<"⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡘"<< endl;
cout<<"⠀⠀⠀⠀⠀⢻⠀⠀⠀⠀⠀⠀⠀⢃⣴⣶⡄⠀⠀⠀⠀⠀⢀⣶⡆⠀⢠⠇"<< endl;
cout<<"⠀⠀⠀⠀⠀⠀⣣⠀⠀⠀⠀⠀⠀⠀⠙⠛⠁⠀⠀⠀⠀⠀⠈⠛⠁⡰⠃⠀"<< endl;
cout<<"⠀⠀⠀⠀⢠⠞⠋⢳⢤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠜⠁⠀⠀"<< endl;
cout<<"⠀⠀⠀⣰⠋⠀⠀⠁⢷⠙⠲⢤⣀⣀⠀⠀⠀⠀⠴⠴⣆⠴⠚⠁⠀⠀⠀⠀"<< endl;
cout<<"⠀⠀⣰⠃⠀⠀⠀⠀⠘⡇⠀⣀⣀⡉⠙⠒⠒⠒⡎⠉⠀⠀⠀⠀⠀⠀⠀⠀"<< endl;
cout<<"⠀⢠⠃⠀⠀⢶⠀⠀⠀⢳⠋⠁⠀⠙⢳⡠⠖⠚⠑⠲⡀⠀⠀⠀⠀⠀⠀⠀"<< endl;
cout<<"⠀⡎⠀⠀⠀⠘⣆⠀⠀⠈⢧⣀⣠⠔⡺⣧⠀⡴⡖⠦⠟⢣⠀⠀⠀⠀⠀⠀"<< endl;
cout<<"⢸⠀⠀⠀⠀⠀⢈⡷⣄⡀⠀⠀⠀⠀⠉⢹⣾⠁⠁⠀⣠⠎⠀⠀⠀⠀⠀⠀"<< endl;
cout<<"⠈⠀⠀⠀⠀⠀⡼⠆⠀⠉⢉⡝⠓⠦⠤⢾⠈⠓⠖⠚⢹⠀⠀⠀⠀⠀⠀⠀"<< endl;
cout<<"⢰⡀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠁⠀⠀⠀⢸⠀⠀⠀⠀⡏⠀⠀⠀⠀⠀⠀⠀"<< endl;
cout<<"⠀⠳⡀⠀⠀⠀⠀⠀⠀⣀⢾⠀⠀⠀⠀⣾⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀"<< endl;
cout<<"⠀⠀⠈⠐⠢⠤⠤⠔⠚⠁⠘⣆⠀⠀⢠⠋⢧⣀⣀⡼⠀⠀⠀⠀⠀⠀⠀⠀"<< endl;
cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠈⠁⠀⠀⠀⠁⠀⠀⢀⡀⠠⠀⠀⠀⠀"<< endl;
}
string Game::get_current_time(){

    string current_time_string="";

    time_t timer;
    struct tm* t;
    timer = time(NULL);
    t = localtime(&timer);

    current_time_string.append( to_string(t->tm_year+1900) );
    current_time_string.append( " 년 "  );

    current_time_string.append( to_string(t->tm_mon+1) );
    current_time_string.append( " 월 "  );
    current_time_string.append( to_string(t->tm_mday) );
    current_time_string.append( " 일 "  );
    current_time_string.append( to_string(t->tm_hour) );
    current_time_string.append( " 시 "  );
    current_time_string.append( to_string(t->tm_min) );
    current_time_string.append( " 분 "  );

    return current_time_string;

}

int main(void){

    int flag = 1;    
    int answer=0;
    

    while(flag)
    {
        cout<< " 1. 게임하기 2. 전적보기 3. 종료하기" << endl;
        cin>> answer;

        if(answer == 1){
            Game mygame;
            int *ptr_arr;
            int count_round=1;

            for (int i=0; i<9; i++){
                cout<< count_round<<" 회 게임 시도 입니다."<<endl;
                ptr_arr = mygame.get_input_from_user();
                if(mygame.compare_with_com_number(ptr_arr)){
                    break;
                }
                count_round++;
            }
            if(count_round==10){
                cout<<"아쉽지만 9회말 종료되었습니다. game over "<< endl;
                mygame.print_gameover2();
            }   
           
            mygame.record_to_file(count_round);
            mygame.record_to_json_file(count_round);

        }
        else if(answer ==2){
            read_from_file();
            // read_from_json_file();
            
        }else if(answer == 3){
            cout<<"게임 종료를 선택하셨습니다. "<< endl;
            flag = 0;
        }
    }


    

    return 0;
}