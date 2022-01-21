// Menu Driven program to implement a Circular Doubly Linked List
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next, *prev;
};

class DoublyCircular{
    private:
    Node *head;
    int counter;
    public:
    DoublyCircular(){
        head=NULL;
        counter=0;
    }

    void insert(int elem, int loc){
        Node *temp= new Node;
        Node *trav= new Node;
        temp->data=elem;
        if(loc==-1)
            loc==counter;
        //EDGE CASE: Empty List
        if(head==NULL){
            head=temp;
            temp->next=head;
            temp->prev=head;
            counter++;
            return;
        }
        bool found=false;
        trav=head;
        int count=0;
        do{
            if(count==loc){
                break;
                found=true;
            }
            count++;
            trav=trav->next;            
        }while(trav!=head);
        if(count<loc){
            cout<<"Index out of bound"<<endl;
            return;
        }
        trav->prev->next=temp;
        temp->prev=trav->prev;
        temp->next=trav;
        trav->prev=temp;
        counter++;
        if(loc==0){
            head=temp;
        }
    }

    // TODO: ERROR: Deletion doesn't work if elements are less than 2
    void delete_elem(int elem){
        Node *trav= head;
        bool found=false;
        if(trav==NULL){
            cout<<"List empty!";
            return;
        }
        //EDGE CASE:Single Element
        else if(trav->next==trav->prev){
            head=NULL;
            delete trav;
            counter--;
            return;
        }
        do{
            if(trav->data==elem){
                if(trav->prev)
                    trav->prev->next=trav->next;
                if(trav->next)
                    trav->next->prev=trav->prev;
                if(trav==head){
                    head=trav->next;
                }
                delete trav;
                counter--;
                found=true;
                break;
            }
            trav=trav->next;
        }while(trav!=head);
        if(!found){
            cout<<"Element Not found!"<<endl;
        }
    }

    void display(){
        Node *trav= new Node;
        trav=head;
        do{
            cout<<trav->data<<' ';
            trav=trav->next;
        }while(trav!=head);
        cout<<endl;
    }
};


int main(){
    DoublyCircular DC;
    int choice, loc, elem;
    cout<<"THE FOLLOWING OPEARTIONS CAN BE PERFORMED ON THE CIRCULAR DOUBLY LINKED LIST:"<<endl;
    cout<<"1.Insert an element at a position"<<endl;
    cout<<"2.Delete an element"<<endl;
    cout<<"3.Display"<<endl;
    cout<<"4.Exit"<<endl;
    while(true){
        cout<<">";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the location (Enter-1 to append):";
                cin>>loc;
                cout<<"Enter the element to insert :";
                cin>>elem;
                DC.insert(elem, loc);
                break;
            case 2:
                cout<<"Enter the element to delete:";
                cin>>elem;
                DC.delete_elem(elem);
                break;
            case 3:
                DC.display();
                break;
            case 4:
                return 0;
            default:
                cout<<"Invalid Choice"<<endl;
        }
    }
}