#include <iostream>
using namespace std;

const int n=3;
class Stack{
    private:
    int arr[n];
    int top;
    public:
    Stack(){
        top=-1;
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(top+1==n){
            return true;
        }
        return false;
    }

    void push(int elem){
        if(!isFull()){
            arr[++top]=elem;
            return;
        }
        cout<<"Overflow";
    }

    int pop(){
        if(!isEmpty()){
            return arr[top--];
        }
        cout<<"underflow!"<<endl;
        return 0;
    }

    int peek(){
        if(!isEmpty()){
            return arr[top];
        }
        cout<<"underflow"<<endl;
        return 0;
    }

    void display(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

class Queue{
    private:
    Stack s1,s2;
    public:
    void enqueue(int elem){
        if(s1.isEmpty()){
            s1.push(elem);
        }
        else{
            while(!s1.isEmpty()){
                s2.push(s1.pop());
            }
            s1.push(elem);
            while(!s2.isEmpty()){
                s1.push(s2.pop());
            }
        }
    }
    int dequeue(){
        return s1.pop();
    }

    void display(){
        while(!s1.isEmpty()){
            s2.push(s1.pop());
        }
        s2.display();
        while(!s2.isEmpty()){
            s1.push(s2.pop());
        }
    }
    
    void view(){
        s1.display();
        s2.display();
    }
};

int main(){
    Queue q;
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.display();
    q.dequeue();
    q.display();
    q.view();
}