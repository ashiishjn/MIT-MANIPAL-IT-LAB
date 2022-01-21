// Program to implement a binary search tree iteratively
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int elem){
        data=elem;
        left=right=NULL;
    }
};

Node *insert(Node* root, int elem){
    Node *temp= new Node(elem);
    Node *parent=NULL;
    Node *child=root;
    if(child==NULL)
        return temp;
    while(child){
        parent=child;
        if(child->data>elem)
            child=child->left;
        else
            child=child->right;
    }
    if(elem<parent->data)
        parent->left=temp;
    else
        parent->right=temp;
    return parent;
}

void inorder(Node *root){ 
    if(!root) 
        return;
    inorder(root->left); 
    cout<<root->data<<" "; 
    inorder(root->right);
}
int main(){
    Node *root=NULL;
    root=insert(root,40);
    insert(root,20);
    inorder(root);
}