// Program to implement an XOR based doubly linked list
#include <iostream>
using namespace std;

struct node{
    int data;
    int both;
};

class XDoubly{
    private:
    node *head;
    public:
    XDoubly(){
        head=NULL;
    }
    void append(int elem){
        node *temp= new node;
        node *trav= new node;
        trav=head;
        temp->data=elem;
        if(trav==NULL){
            temp->both=0^(int)temp;
            cout<<(int)temp<<endl<<temp->both;
        }
        else{
            while(trav->both!=0)
        }
    }
};

int main(){
    XDoubly x;
    x.append(100);
}