// Program to check if a string is a palindrome using Stack
#include <iostream>
using namespace std;
#define STACK_SIZE 22
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

    int pop(){
        if(top!=-1)
            return arr[top--];
        cout<<"Stack Underflow!"<<endl;
        return -1;
    }

    int peek(){
        if(top!=-1)
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

int main(){
    Stack stk1;
    string a;
    cout<<"Enter String:";
    getline(cin, a);
    for(int i=0;i<a.length();i++)
        stk1.push(a[i]);
    
    int i;
    for( i=0 ; (i<a.length())&&(stk1.pop()==a[i]) ;++i);

    if(i == a.length())
        cout<<"String is a palindrome.";
    else
        cout<<"String is not a palindrome.";
}