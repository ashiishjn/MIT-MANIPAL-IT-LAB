//Program to implement Binary Tree
#include <iostream>
#include <queue>
#include <stack>
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
        cout<<"Use -1 to break"<<endl;
        cout<<"Enter root"<<endl;
        root=createTree();
    }

    void iterativePreorder() const{
        cout<<"Iterative Preorder Traversal >>";
        if(root==NULL) 
            return;
        stack <Node*> S;
        Node *curr= root;
        S.push(curr);
        while(!S.empty()){
            curr=S.top();
            S.pop();
            cout<<curr->data<<' ';
            if(curr->rc)
                S.push(curr->rc);
            if(curr->lc)
                S.push(curr->lc);
        }
        cout<<endl;
    }

    void iterativeInorder() const{
        cout<<"Iterative Inorder Traversal >>";
        if(root==NULL)
            return;
        stack <Node*> S;
        Node *curr=root;
        while(curr!=NULL || !S.empty()){
            while(curr!=NULL){
                S.push(curr);
                curr=curr->lc;
            }
            curr=S.top();S.pop();
            cout<<curr->data<<' ';
            curr=curr->rc;
        }
        cout<<endl;
    }

    void iterativePostorder() const{
        cout<<"Iterative Postorder Traversal >>";
        if(root==NULL)
            return;
        stack <Node*> S;
        Node *curr=root;
        do{
            while(curr){
                if(curr->rc)
                    S.push(curr->rc);
                S.push(curr);
                curr=curr->lc;
            }
            curr=S.top();
            S.pop();
            if(curr->rc && S.top()==curr->rc){
                S.pop();
                S.push(curr);
                curr=curr->rc;
            }
            else{
                cout<<curr->data<<' ';
                curr= NULL;
            }            
        }while(!S.empty());
        cout<<endl;
    }

    bool searchParent(Node *curr, int elem) const{
        if(curr->lc){
            if(curr->lc->data==elem){
                cout<<"Parent is "<<curr->data<<endl;
                return true;
            }
            else
                searchParent(curr->lc,elem);
        }
        if(curr->rc){
            if(curr->rc->data==elem){
                cout<<"Parent is "<<curr->data<<endl;
                return true;
            }
            else
                searchParent(curr->rc,elem);
        }
        return false;
    }

    void parent(int elem) const{
        if(root->data==elem){
            cout<<"Root has no parent"<<endl;
            return;
        }
        else{
            if(!searchParent(root,elem))
                cout<<"Element does not exist in the tree"<<endl;
        }
    }

    int counter(Node *node) const{
        if (node == NULL) 
            return 0;  
        int lDepth=counter(node->lc);
        int rDepth=counter(node->rc);
        // Return larger of both plus one for root
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else 
            return(rDepth + 1);

    }

    void level() const{
        int v=counter(root);
        cout<<"Total Depth is:"<<v<<endl;
    }

    bool searchAncestor(Node *node, int elem) const{
        if (node == NULL) 
            return false; 
        else if (node->data ==elem) 
            return true; 
        else if ( searchAncestor(node->lc, elem) || searchAncestor(node->rc,elem) ) { 
            cout << node->data << " "; 
            return true; 
        }
        return false;
    }

    void ancestors(int elem) const{
        if(root->data==elem)
            cout<<"Root element has no ancestor"<<endl;
        else{
            if(!searchAncestor(root,elem))
                cout<<"Element does not exist in the tree"<<endl;
        }
        cout<<endl;
    }

    int leafcount(Node *node){
        if(node==NULL)
            return 0;
        else if(!node->lc && !node->rc)
            return 1;
        else
            return leafcount(node->lc)+leafcount(node->rc);
    }

    void leafs(){
        cout<<"Leafs present:"<<leafcount(root)<<endl;
    }
};

int main(){
    Tree T;
    T.create();
    T.iterativeInorder();
    // T.iterativePostorder();
    T.iterativePreorder();
    int n;
    cout<<"Find parent of?";
    cin>>n;
    T.parent(n);
    T.level();
    cout<<"Find ancestor of?";
    cin>>n;
    T.ancestors(n);
    T.leafs();
}
