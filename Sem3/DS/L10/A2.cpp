// Program to check if two binary trees are mirror images of each other using recursive checking
#include <iostream>
using namespace std;

struct Node{
    Node *lc, *rc;
    int data;
};

class Tree{
    private:
    Node *root;
    public:

    Tree(int arr[],int n){
        root= insertLevelOrder(arr,0,n);
    }


    Node* insertLevelOrder(int arr[], int i, int n){
        if(i>=n)
            return NULL; 
        Node *temp = new Node();
        temp->data=arr[i];
        temp->lc = insertLevelOrder(arr, 2*i+1, n);
        temp->rc = insertLevelOrder(arr, 2*i+2, n);
        return temp;
    }

    int Mirror(Node* a, Node* b){
        if (!a && !b) 
            return true;  
        if (!a || !b) 
            return false; 
        return  a->data == b->data && Mirror(a->lc, b->rc) && Mirror(a->rc, b->lc); 
    }

    bool isMirror(Tree t2){
        return Mirror(root, t2.root);
    } 
};

int main(){
    int arr1[]={2,3,4};
    int arr2[]={2,4,3};
    Tree t1(arr1,3);
    Tree t2(arr2,3);
    t1.isMirror(t2)?cout<<"Yes":cout<<"No";
    return 0;
}