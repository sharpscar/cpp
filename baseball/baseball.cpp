#include "./game.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <array>



using namespace std;

Game::Game(){
    srand(time(NULL));

    // com_num = {0};array<int,3> com_num
    com_num[3] = {};

    for (int i=0; i< 3; i++){
        
        com_num[i] = (rand() % 9 )+1;
        for(int j=0; j<i; j++)
            if(com_num[i] ==com_num[j]) 
            {
                i--;
                break;
            }
        cout<< "com_num[i]"<<com_num[i]<< endl;
                
    }

    // while(com_num[0]!=com_num[1] && com_num[1] != com_num[2]&& com_num[0]!= com_num[2])
    // {
    //     for (int i=0; i< 3; i++){
    //         com_num[i] = (rand() % 9 )+1;
    //         cout<< "com_num[i]"<<com_num[i]<< endl;
    //     }

    // }
    
    // for (int i=0; i< 3; i++){
    //     com_num[i] = (rand() % 9 )+1;
    //     cout<< "com_num[i]"<<com_num[i]<< endl;
    // }
    

}
int*  Game::get_input_from_user(){
    //사용자로 부터 입력을 받아서  user_num 배열에 하나씩 할당!
    int static user_num[3];
    int num=0;
    std::cout << "첫번째 숫자를 입력하세요 : ";
    std::cin >>num;
    user_num[0] = num;
    std::cout << "두번째 숫자를 입력하세요 : ";
    std::cin >> num;
    user_num[1] = num;
    std::cout << "세번째 숫자를 입력하세요 : ";
    std::cin >>  num;
    user_num[2] = num;
    // for (int i=0; i<3; i++){
        
    //     cout<< "user_num[i]  : "<<user_num[i]<< endl;
    // }

    return user_num;

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

    // for(int i=0; i<3; i++){
    //     std::cout << com_num[i]  << std::endl;
    // }

    for (int i =0; i<3 ; i++){

        for(int j=0 ; j<3 ; j++){
            // 위치도 같고 값도 같으면
            if(com_num[i] == user_num[j] && i == j){
                // std::cout << "3스트라이크 게임 종료!"<< std::endl;
                cout << "strike     :"<< strike <<endl;

                cout << "com_num[i]     :"<< com_num[i] <<endl;
                cout << "user_num[i]     :"<< user_num[i] <<endl;
                strike++;


            }else if(com_num[i]== user_num[j] && i != j){
                ball++;
            }
            
        }
    }

    std::cout <<" strike is "<< strike << std::endl;
    std::cout <<" ball is "<< ball << std::endl;

    // if (strike==3){
    //     cout <<" 3 strike! game over "<<  endl;
    //     //   return 0;

    // }
    
}


int main(){

    Game mygame;

    // int com_num[3] = {0,};
    int user_num[3] = {0,};
    
    int *user_n_ptr = user_num;
    

    user_n_ptr = mygame.get_input_from_user();

    mygame.compare_with_com_number(user_n_ptr);
    

    return 0;
}