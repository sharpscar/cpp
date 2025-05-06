#include "./queue.h"
#include <cstdlib> //  또는  stdlib.h rand()를 위해

// Queue 메서드들 
Queue::Queue(int qs) : qsize(qs){
    front = rear = NULL;
    items =0;
}

Queue::~Queue(){
    Node * temp;
    /*
    queue가 아직 비어있지 않으면
    1.머리항목의 주소를 임시로 저장
    2.front를 그 다음항목으로 다시 설정
    3.이전 머리노드를 삭제
    */
    while(front !=NULL){
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::isempty() const{
    return items ==0;
}

bool Queue::isfull() const{
    return items == qsize;
}

int Queue::queuecount() const{
    return items;
}


//큐에 항목을 추가한다.
bool Queue::enqueue(const Item &item){
    if(isfull())
        return  false;
    Node *add = new Node;  //노드를 생성 하지만 실패했을 경우 new는 std::bas_alloc 예외를 발생시킨다.
    add->item = item;
    add->next = NULL;
    items ++;
    if(front == NULL)
        front = add;
    else    
        rear->next = add;
    rear = add;
    return true;
}

bool Queue::dequeue(Item &item){
    if(front == NULL)
        return false;
    item = front->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if(items ==0)
        rear = NULL;
    return true;
}

//when은 고객이 도착한 시간이다 도착시간은 when으로 설정된다. 처리시간은 1,2,3중에서 무작위로 한값이 설정된다.
void Customer::set(long when){
    processtime = std::rand() %3 +1;
    arrive =when;
}