//Program to evaluate a Postfix expression
#include <iostream>
#include <stdlib.h>
using namespace std;
const int STACK_SIZE=100;
class Stack {
    private:
    int top;
    int arr[STACK_SIZE];
    public:
    Stack(){
        top=-1;
    }
    void push(int elem){
        if(top<STACK_SIZE){
            arr[++top]=elem;
        }
        else{
            cout<<"Overflow"<<endl;
        }
    }

    int pop(){
        if(top>=0)
            return arr[top--];
        cout<<"Stack Underflow!"<<endl;
        return -1;
    }

    int peek(){
        if(top>=0)
            return arr[top];
        else{
            cout<<"Underflow"<<endl;
            return -1;
        }
    }

    void display(){
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<endl;
        }
    }
};

int Operator(char ch, int a, int b){
    switch(ch){
        case '*': return(a*b);break;
        case '+': return(a+b);break;
        case '-': return(a-b);break;
        case '/': return(a/b);break;
        case '$': return(a^b);break;
        case '^': return(a^b);break;
        default:
        return 0;
    }
}

int postEval(string post){
    Stack s;
    int l=post.length();
    for(int i=0;i<l;i++){
        if(isdigit(post[i])){
            s.push(post[i]-'0');
        }
        else{
            s.push(Operator(post[i],s.pop(),s.pop()));
        }
    }
    return s.peek();
}

int main(){
    string s;
    cout<<"Enter expression:";
    cin>>s;
    cout<<postEval(s);
}