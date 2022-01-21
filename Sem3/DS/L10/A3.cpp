// Program to copy one tree to another
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *lc, *rc;
};

class Tree{
    private:
    Node *root;

    protected:
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
    public:

    Tree(){
        root=NULL;
    }

    void create(){
        root=createTree();
    }

    void post(Node *node) const{
        if (node == NULL) 
            return;  
        post(node->lc);
        post(node->rc);
        cout<<node->data <<" "; 
    }
    void PostOrder() const{
        cout<<"Postorder Traversal >>";
        post(root);
        cout<<endl;
    }

    // This function employs operator overriding to copy a tree
    Node* copy(Node* src){
        if(!src)
            return NULL;
        Node *dest= new Node;
        dest->data=src->data;
        dest->lc=copy(src->lc);
        dest->rc=copy(src->rc);
        return dest;

    }

    void operator=(Tree t2){
        root=new Node;
        root=copy(t2.root);
    }
};

int main(){
    Tree t1,t2;
    t1.create();
    t1.PostOrder();
    t2=t1;
    t2.PostOrder();
}