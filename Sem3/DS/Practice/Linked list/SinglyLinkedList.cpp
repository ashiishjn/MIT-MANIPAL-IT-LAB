//Program to implement singly linked list
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using namespace std;

struct node{
    int data;
    node* next; //Pointer to type node
};

class list{
    private:
    node *head, *tail; // Every linked list has a head and a tail
    public:
    static int counter;
    list(){
        head=NULL;
        tail=NULL;
    }
    void insert(int elem, int loc);
    void display();
    int find(int elem);
    int remove(int loc);
};

int list::counter=0;

void list::insert(int elem, int loc=counter){
    if(loc==0 & counter!=0){
        node *temp=new node;
        temp->data=elem;
        temp->next=head;
        head=temp;
        counter++; 
    } 
    else if(loc<counter){
        node *temp= new node;
        node *pre= new node;
        node *cur= new node;
        cur=head;
        for(int i=0;i<loc;i++){
            pre=cur;
            cur=cur->next;
        }
        temp->data=elem;
        pre->next=temp;
        temp->next=cur;
        counter++;
    }
    else if(loc==counter){
        node *temp=new node;
        temp->data=elem;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        counter++;
    }
    else{
        cout<<"Index out of bound"<<endl;
    }
}

int list::remove(int loc=counter){
    if(loc==0){
        node *temp=new node;
        temp=head;
        head=head->next;
        delete temp;
        counter--;
    }
    else if(loc<counter){
        node *current=new node;
        node *previous=new node;
        current=head;
        for (int i=0;i<loc;i++){
            previous=current;
            current=current->next;
        }
        previous->next=current->next;
        counter--;
    }
    else if(loc==counter-1){
        node *current=new node;
        node *previous=new node;
        current =head;
        while(current->next!=NULL){
            previous=current;
            current=current->next;
        }
        tail=previous;
        previous->next=NULL;
        delete current;
        counter--;
    }
    else{
        cout<<"Wrong Index"<<endl;
    }
}

void list::display(){
    node *temp=new node;
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int list::find(int data){
	int index = 0;
	node * temp = head;
	while(temp!=NULL){
		if(temp->data == data){
			return index;
		}
		temp = temp->next;
		index++;
	}
	return -1; 
}

int main(){
    list l;
    int choice;
    char ch='y';
    int loc,elem,c;
    cout<<"1.Insert before another element"<<endl;
    cout<<"2.Insert after another element"<<endl;
    cout<<"3.Delete an element"<<endl;
    cout<<"4.Traverse the list"<<endl;
    cout<<"5.Reverse the list"<<endl;
    cout<<"6.Sort the list"<<endl;
    cout<<"7.Delete alternate elements"<<endl;
    cout<<"8.Insert in an order:"<<endl;
    cout<<"9.Insert in a position:"<<endl;
    cout<<"10.Exit"<<endl;
    do{
        cout<<"Enter the choice:";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the element to insert before:"<<endl;
                cin>>c;
                cout<<"Enter the element to insert:"<<endl;
                cin>>elem;
                loc= l.find(c);
                cout<<loc;
                if(loc==0)
                    l.insert(elem,loc);
                else if(loc<0)
                    cout<<"Doesn't exist!"<<endl;
                else
                    l.insert(elem,loc);
                break;
            case 2:
                cout<<"Enter the element to insert after:"<<endl;
                cin>>c;
                cout<<"Enter the element to insert:"<<endl;
                cin>>elem;
                loc= l.find(c);
                cout<<loc;
                if(loc==l.counter-1)
                    l.insert(elem,loc);
                else if(loc<0)
                    cout<<"Doesn't exist!"<<endl;
                else
                    l.insert(elem,loc+1);
                break;
            case 3:
                cout<<"Enter the element to delete:"<<endl;
                cin>>elem;
                loc=l.find(elem);
                if(loc!=-1)
                    l.remove(loc);
                else
                    cout<<"Element doesn't exist"<<endl;
                break;
            case 4:
                l.display();
                break;
            case 9:
                cout<<"Enter the element to insert:"<<endl;
                cin>>elem;
                l.insert(elem);
                break;
        }
        cout<<"Do you want to continue?Y/N";
        // cin>>ch;
    }while(ch=='y');
}
