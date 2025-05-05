#ifndef QUEUE_H_
#define QUEUE_H_



//이 큐는 customer항목들을 포함하게된다.

class Customer{
    private:
        long arrive;
        int processtime;

    public:
        Customer(){arrive= processtime=0;}
        void set(long when);
        long when() const { return arrive;}
        int ptime() const{return processtime;}
};

typedef Customer Item;

class Queue{
    private:
        struct Node {Item item; struct Node *next;};
        enum{ Q_SIZE = 10};

        Node *front;
        Node *rear;
        int items;
        const int qsize;

        //public 복사를 방지하는 선점 정의
        Queue(const Queue &q): qsize(0){}
        Queue &operator=(const Queue &q) {return *this;}
    
    public:
        Queue(int qs = Q_SIZE);  //qs 한계를 가진 큐를 생성한다.
        ~Queue();
        bool isempty() const;
        bool isfull() const;
        int queuecount() const;
        bool enqueue(const Item &item);
        bool dequeue(Item &item);

};
#endif