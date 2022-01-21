// Program to merge two single linked list
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* createList(){
    Node *temp= new Node;
    cout<<">";
    int elem;
    cin>>elem;
    if(elem==-1)
        return NULL;
    else{
        temp->data=elem;
        temp->next=createList();
        return temp;
    }
}

void traverse(Node *temp){
    cout<<temp->data<<" ";
    if(temp->next)
        traverse(temp->next);
    return;
}

Node* merger(Node *head1, Node *head2){
    Node* head;
    if(!head1 && !head2)
        return NULL;
    else if(!head1)
        return head2;
    else if(!head2)
        return head1;
    if(head1->data<head2->data){
        head=head1;
        head->next=merger(head1->next,head2);
    }
    else{
        head=head2;
        head->next=merger(head1,head2->next);
    }
    return head;
}

int main(){
    Node *head1 = createList();
    traverse(head1);
    cout<<endl;

    Node *head2 = createList();
    traverse(head2);
    cout<<endl;

    Node *head3 = merger(head1,head2);
    traverse(head3);
}