// Program to implememt a binary search tree
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

Node* insert(Node *root,int elem){
    if(root==NULL)
        return new Node(elem);       
    if(elem>root->data)
        root->right=insert(root->right,elem);
    else
        root->left=insert(root->left,elem);
}


Node* search(Node *root, int elem){
    if(root==NULL||root->data==elem)
        return root;
    else if(root->data<elem)
        return search(root->right, elem);
    else
        return search(root->left,elem);
}

void inorder(Node *root){ 
    if(!root) 
        return;
    inorder(root->left); 
    cout<<root->data<<" "; 
    inorder(root->right);
}

Node* deleteNode(Node* root, int elem){
    if(root==NULL)
        return root;
    if(elem>root->data)
        root->right=deleteNode(root->right,elem);
    else if(elem<root->data)
        root->left=deleteNode(root->left,elem);
    else{
        Node *temp;
        if(root->left==NULL){
            temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            temp= root->left;
            delete root;
            return temp;
        }
        else{
            // Both children exist
            temp=root;
            while(temp && temp->left){
                temp=temp->left;
            }
            root->data=temp->data;
            root->right=deleteNode(root->right, temp->data);
        }
    }
}


int main(){
    Node *root=NULL;
    root=insert(root,30);
    int n, choice;
    cout<<"1. Insert an element "<<endl;
    cout<<"2. Delete an element "<<endl;
    cout<<"3. Search an element "<<endl;
    cout<<"4. Print the array "<<endl;
    while(true){
        cout<<">";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter element:";
                cin>>n;
                insert(root,n);
                break;
            case 2:
                cout<<"Enter element:";
                cin>>n;
                deleteNode(root,n);
                break;
            case 3:     
                cout<<"Enter element:";
                cin>>n;
                search(root,n)?cout<<"Yes"<<endl:cout<<"NO"<<endl;
                break;
            case 4:
                inorder(root);
                cout<<endl; 
                break;
            default:
                cout<<"Invalid Choice!"<<endl;
        }
    }
}