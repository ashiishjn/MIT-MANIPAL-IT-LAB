//Program to convert an Infix expression to a Postfix expression
#include <iostream>
#include <stdio.h>
using namespace std;
#define STACK_SIZE 100
class Stack {
    private:
    int top;
    char arr[STACK_SIZE];
    public:
    Stack(){
        top=-1;
    }
    void push(int elem){
        if(top!=STACK_SIZE-1){
            arr[++top]=elem;
        }
        else{
            cout<<"Overflow"<<endl;
        }
    }

    char pop(){
        if(top!=-1)
            return arr[top--];
        return -1;
    }

    char peek(){
        if(top!=-1)
            return arr[top];
        else{
            return -1;
        }
    }
};

int getPriority(char c){
    switch (c){
        case '-':
        case '+':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '$':
        case '^':
            return 3;
            break;
        default:
            return 0;
    }
}

string infixtoPostfix(string infix){
    infix='('+infix+')';
    int l=infix.size();
    string output;
    Stack s;
    for(int i=0;i<l;i++){
        if(isalpha(infix[i])||isdigit(infix[i]))
            output+=infix[i];
        else if(infix[i]=='(')
            s.push(infix[i]);
        else if(infix[i]==')'){
            while(s.peek()!='(')
                output+=s.pop();
            s.pop();
        }
        else{
            while(getPriority(infix[i])<=getPriority(s.peek()))
                output+=s.pop();
            s.push(infix[i]);
        }
    }
    return output;
}

int main(){
    string s;
    cout<<"Enter the string:";
    cin>>s;
    cout<<infixtoPostfix(s);
}