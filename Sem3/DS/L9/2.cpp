//Program to represemt a polynomial using Circular Doubly Linked List
#include <iostream>
using namespace std;
struct node{
    int coff;
    int exp;
    node *prev;
    node *next;
};

class Poly{
    private:
    node *head;
    public:
    Poly(){
        head=NULL;
    }

    void append(int c, int e){
        node *temp= new node;
        node *trav= new node;
        temp->coff=c;
        temp->exp=e;
        trav=head;
        if(trav==NULL){
            head=temp;
            temp->next=head;
            temp->prev=head;
            return;
        }
        trav->prev->next=temp;
        trav->prev=temp;
        temp->next=trav;
        temp->prev=trav->prev;
    }

    void input(){
        int c,e;
        cout<<"Enter the polynomial."<<endl;
        while(true){
            cout<<"Enter the coff:";
            cin>>c;
            cout<<"Enter the exp:";
            cin>>e;
            if(e==0 && c==0)
                break;
            append(c,e);
            if(e==0)
                break;
        }
    }

    node* adder(node* p1, node *p2){
        cout<<"inside"<<endl;
        if(!p1)
            return p2;
        if(!p2)
            return p1;
        node *temp= new node;
        if(p1->exp=p2->exp){
            temp->exp=p1->exp;
            temp->coff=p1->coff+p2->coff;
            temp->next=adder(p1->next,p2->next);
        }
        else if(p1->exp>p2->exp){
            // node *temp= new node;
            temp->exp=p1->exp;
            temp->coff=p1->coff;
            temp->next=adder(p1->next,p2);
        }
        else{
            // node *temp= new node;
            temp->exp=p2->exp;
            temp->coff=p2->coff;
            temp->next=adder(p1,p2->next);
        }
        return temp;
    }

    void add3(Poly p1, Poly p2){
        head=adder(p1.head, p2.head);
        return;
    }

    void add2(Poly p1, Poly p2){
        node *trav =p1.head;
        node *trav2= p2.head;
        node *curr=new node;
        head =curr;
        while(trav && trav2){
            if(trav->exp>trav2->exp){
                curr->exp=trav->exp;
                curr->coff=trav->coff;
                trav=trav->next;
            }
            else if(trav->exp<trav2->exp){
                curr->exp=trav2->exp;
                curr->coff=trav2->coff;
                trav2=trav2->next;
            }
            else{
                curr->exp=trav->exp;
                curr->coff=trav->coff+trav2->coff;
                trav=trav->next;
                trav2=trav2->next;
            }
            curr->next=new node;
            curr=curr->next;
            curr->next=NULL;

        }
        while(trav->next||trav2->next){
            if(trav->next){
               curr->exp=trav->exp;
               curr->coff=trav->coff;
               trav=trav->next; 
            }
            if(trav2->next){
               curr->exp=trav2->exp;
               curr->coff=trav2->coff;
               trav2=trav2->next; 
            }
            curr->next=new node;
            curr=curr->next;
            curr->next=NULL;
        }
    }

    void add(Poly p1, Poly p2){
        // Copy one polynomial
        node *trav= new node;
        trav=p1.head;
        do{
            append(trav->coff,trav->exp);
            trav=trav->next;
        }while(trav!=p1.head);
        // Add second polynomial
        trav=p2.head;
        bool found;
        do{
            found=false;
            node *temp= head;
            do{
                if(trav->exp==temp->exp){
                    found=true;
                    temp->coff=temp->coff+trav->coff;
                    break;
                }
                temp=temp->next;
            }while(temp!=head);
            if(!found){
                node *value= new node;
                value->exp=trav->exp;
                value->coff=trav->coff;
                node *ex=head;
                do{
                    if(ex->exp>trav->exp){
                        value->next=ex->next;
                        value->prev=ex;
                        ex->next->prev=value;
                        ex->next=value;
                    } 
                }while(ex!=head);
            }
            trav=trav->next;
        }while(trav!=p2.head);
    }

    void display(){
        node *trav= new node;
        trav=head;
        if(trav->next==head){
            if(trav->exp==0)
                cout<<trav->coff<<endl;
            else
                cout<<trav->coff<<"x^"<<trav->exp<<endl;
            return;
        }
        do{
            cout<<trav->coff<<"x^"<<trav->exp<<" + ";
            trav=trav->next;
        }while(trav->next!=head);
        cout<<trav->coff;
        cout<<endl;
    }
};

int main(){
    Poly P1,P2,P3;
    P1.input();
    P2.input();
    P3.add3(P1, P2);
    cout<<"Polynomial 1:";
    P1.display();
    cout<<"Polynomial 2:";
    P2.display();
    cout<<"Polynomial 3:";
    P3.display();
}