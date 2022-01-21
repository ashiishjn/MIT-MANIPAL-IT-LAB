// Program to implement queues using Linked List
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node * next;
};

class Queues{
    private:
    Node *front, *rear;
    public:
    Queues(){
        front=rear=NULL;
    }
    void enqueue(int elem){
        Node *temp= new Node;
        temp->data=elem;
        temp->next=NULL;
        if(rear)
            rear->next=temp;
        rear=temp;
        if(!front)
            front=temp;
    }

    int dequeue(){
        if(!front && !rear)
            return -1;
        Node *trav=front;
        int d=trav->data;
        if(front==rear)
            front=rear=NULL;
        else{
            front=front->next;
        }
        return d;
    }

    void display(){
        Node *trav=front;
        while(trav!=NULL){
            cout<<trav->data<<" ";
            trav=trav->next;
        }
        cout<<endl;
    }
};

int main(){
    Queues q;
    q.enqueue(11);
    q.display();
    q.enqueue(12);
    q.display();
    q.enqueue(13);
    q.display();
    q.enqueue(14);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
}