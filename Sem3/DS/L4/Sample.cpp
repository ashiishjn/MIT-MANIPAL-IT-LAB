#include <iostream>
using namespace std;
const int SIZE=100;
class Queue{
    private:
    int front;
    int rear;
    int arr[SIZE];
    public:
    Queue(){
        rear=front=-1;
    }

    inline bool isEmpty(){
        return front==-1 && rear==-1;
    }
    
    inline bool isFull(){
        return rear==SIZE-1;
    }
    
    void enq(int elem){
        if(isFull())
            return;
        if(isEmpty())
            front++;
        arr[++rear]=elem;

    }
    int deq(){
        if(isEmpty()){
            cout<<"Empty Queue";
            return -1;    
        }
        else if(front==rear){
            int temp=arr[rear];
            front=rear=-1;
            return temp;
        }
        else{
            return arr[front++];
        }
    }
    
    void display(){
        if(isEmpty()){
            cout<<endl;
            return;
        }

        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Queue Q;
    Q.display();
    Q.enq(1);
    Q.display();
    Q.deq();
    Q.display();
    Q.enq(2);
    Q.display();
    Q.enq(3);
    Q.display();
    Q.enq(4);
    Q.display();
    Q.deq();
    Q.display();
    Q.deq();
    Q.display();
    Q.enq(5);
    Q.display();
}