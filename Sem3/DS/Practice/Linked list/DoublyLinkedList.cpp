// Program to implement doubly linked list
#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
};

class Doubly{
    private:
    node *head, *tail;
    public:
    Doubly(){
        head=NULL;
        tail=NULL;
    }

    void display(){
        node *temp=new node;
        temp=head;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }

    void insert_at_begin(int elem){
        node *temp= new node;
        temp->data= elem;
        temp->prev=NULL;
        temp->next=head;
        head=temp;
        if(tail==NULL){
            tail=temp;
        }
    }

    void insert_at_end(int elem){
        node *temp=new node;
        temp->data=elem;
        temp->next=NULL;
        temp->prev=tail;
        temp->prev->next=temp;
        tail=temp;
        if(head==NULL){
            head=temp;
        }
    }

    // void insert_at_position(int elem){
    //     node *temp=new node;
    //     temp->data=elem;

    // }
};

int main(){
    Doubly d;
    d.insert_at_begin(40);
    d.insert_at_begin(30);
    d.display();
    d.insert_at_end(20);
    d.display();
    
}