// Program to check if the parenthesis are balanced
#include <iostream>
#include <string.h>
#define STACK_SIZE 100
char open[]={'{','[','('};
char close[]={'}',']',')'};
using namespace std;
class Stack {

    private:
    int top;
    char arr[STACK_SIZE]={'\0'};

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

    char pop(){
        if(top>=0)
            return arr[top--];
        return -1;
    }

    char peek(){
        if(top>=0)
            return arr[top];
        else{
            return -1;
        }
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }
};

int main(){
    Stack para;
    char ch[50];
    gets(ch);
    int n=strlen(ch);
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            if(open[j]==ch[i]){
                para.push(ch[i]);
            }
            else if(ch[i]==close[j] & para.peek()==open[j]){
                para.pop();
            }
        }
    }
    if (para.isEmpty()){
        cout<<"Paranthesis are balanced."<<endl;
        return 1;
    }
    cout<<"Paranthesis are not balanced."<<endl;
    return 0;
}