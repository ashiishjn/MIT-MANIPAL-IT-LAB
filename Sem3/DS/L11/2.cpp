// Program to implement expression trees
#include <iostream>
#include <stack>
using namespace std;
struct Node{
    char data;
    Node *left, *right;
    Node(int c){
        data=c;
        left=right=NULL;
    }
};

bool isoperator(char c){
    return c=='+'||c=='-'||c=='/'||c=='*';
}

Node* createTree(string postfix){
    stack<Node*> s;
    for (int i=0;i<postfix.length();i++){
        if (!isoperator(postfix[i])){
            Node *temp= new Node(postfix[i]);
            s.push(temp);
        }
        else{
            Node *temp= new Node(postfix[i]);
            temp->right=s.top();s.pop();
            temp->left=s.top();s.pop();
            s.push(temp);
        }
    }
    return s.top();
}

void infix(Node *root){
    if(root==NULL)
        return;
    infix(root->left);
    cout<<root->data;
    infix(root->right);
}
int operate(int a, int b, char c){
    switch(c){
        case '+':
            return a+b;
            break;
        case '-':
            return a-b;
            break;
        case '*':
            return a*b;
            break;
        case '/':
            return a/b;
            break;
    }
}
int evaluate(Node *root){
    if(isdigit(root->data)){
        return root->data-'0';
    }
    else{
        int left=evaluate(root->left);
        int right=evaluate(root->right); 
        return operate(left,right,root->data);
    }
}
int main(){
    string s;
    cout<<"Enter a postfix expression";
    cin>>s;
    Node *root=createTree(s);
    infix(root);
    cout<<endl<<evaluate(root);
}