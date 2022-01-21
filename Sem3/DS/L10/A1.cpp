// Program to check for equality of Binary Trees using level order Traversal
// Applied Operator Overloading
#include <iostream>
#include <queue>
using namespace std;

struct Node{
    Node *lc, *rc;
    int data;
};

class Tree{
    private:
    Node *root;
    public:
    Tree(){
        root= createTree();
    }
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

    bool operator==(Tree sec){
        if(!root && !sec.root)
            return true;
        queue <Node*> q1,q2;
        q1.push(root);
        q2.push(sec.root);
        while(!q1.empty() && !q2.empty()){
            Node *n1=q1.front();
            Node *n2=q2.front();
            q1.pop();
            q2.pop();
            if(n1->data!=n2->data)
                return false;
            if(n1->lc && n2->lc){
                q1.push(n1->lc);
                q2.push(n2->lc);
            }
            else if (n1->lc || n2->lc) 
                return false;
            if(n1->rc && n2->rc){
                q1.push(n1->rc);
                q2.push(n2->rc);
            }
            else if (n1->rc || n2->rc)
                return false;

        }
        return true;
    }
};

int main(){
    cout<<"Enter root of Tree 1:"<<endl;
    Tree t1;
    cout<<"Enter root of Tree 2:"<<endl;
    Tree t2;
    t1==t2?cout<<"Yes":cout<<"No";
    return 0;
}