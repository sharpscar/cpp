#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Game{
    private:
        int com_num[3];
        int user_num[3];
        bool game_record;
    public:
        Game();
        
        /**유저로부터 숫자 입력을 받는 함수 */
        int * get_input_from_user();

        /** 
         * 이 안에서  비교판단한다.
         * com number와 user number가 위치와 값이 전부 동일하면 3스트라이크 라고 출력 하고 1을 리턴한다.
         * 위치는 다르지만 값이 동일하면 3볼 
         *int Game::compare_with_com_number(int * user_num){
         */

         
        int compare_with_com_number(int * user_num);    //비교하여 문자열을 출력한다.  

        /**원래는 count_round또한 game클래스 내에 만들어야한다.
         *  하지만 그렇게하면 set_round_count, get_round_count 또한 
         *  생성해야한다.
         * */
        void record_to_file(int count_round);
        void record_to_json_file(int count_round);
        void read_from_json_file();
        void read_from_file();
        string get_current_time();
        void print_gameover();
        void print_gameover2();


};