#include "./stack.h"

// 빈 스택을 생성
Stack::Stack(){
    top =0;
}

bool Stack::isempty() const{
    return top ==0;
}
bool Stack::isfull() const{
    return top == MAX;
}


/** item을 추가한다.
 *  잘 추가되었으면 true
 *  만약 더이상 넣을공간이 없으면 false
 *  를 리턴 */
bool Stack::push(const Item & item){
    
    if(top <MAX){
        items[top++] = item;
        return true;
    }else
        return false;
}

bool Stack::pop(Item & item){
    if(top >0){
        item = items[--top];
        return true;
    }else
        return false;

}