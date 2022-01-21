//Program to implement Binary Tree
#include <iostream>
#include <queue>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *lc, *rc;
};

class Tree{

    private:
    Node *root;
    vector<int> a;
    public:
    Node* createTree(){
        int val;
        cout<<">";
        cin>>val;
        if(val==-1)
            return NULL;
        Node *temp= new Node;
        temp->data=val;   
        cout<<"Left child of "<<val<<endl;
        temp->lc=createTree();
        cout<<"Right child of "<<val<<endl;
        temp->rc=createTree();
    }

    void in(Node *node) {
        if(node == NULL)
            return;
        in(node->lc);
        a.push_back(node->data);
        in(node->rc);
    }

    Tree(){
        root=NULL;
    }

    void create(){
        cout<<"Use -1 to break"<<endl;
        cout<<"Enter root"<<endl;
        root=createTree();
    }
    void inq(){
        in(root);
    }
    vector<int> ret(){
        return a;
    }
    
};
void print(vector<int>a){
    for(int i=0;i<a.size();i++){
        cout<<a.at(i)<<" ";
    }
    cout<<endl;
}

int main(){
    Tree t;
    t.create();
    t.inq();
    print(t.ret());
}