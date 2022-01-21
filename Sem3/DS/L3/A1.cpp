//Program to implement N stacks in a single array
#include <iostream>
using namespace std;
const int SIZE=10;
const int N=5;
class NStacks{
    private:
    int arr[SIZE]={0};
    int top[N];
    int bot[N+1];
    public:
    NStacks(){
        for(int i=0,j=-1;i<N;i++,j+=SIZE/N){
            top[i]=j;
            bot[i]=j;
        }
        bot[N]=SIZE-1;
    }
    bool isEmpty(int stk){
        if(top[stk]==bot[stk]){
            return true;
        }
        return false;
    }

    bool isFull(int stk){
        if(top[stk]+1==bot[stk+1]){
            return true;
        }
        return false;
    }

    int push(int elem, int stk){
        if(!(isFull(stk))){
            arr[++top[stk]]=elem;
            return 1;
        }
        return -1;
    }

    int pop(int stk){
        if(!isEmpty(stk)){
            return arr[top[stk]--];
        }
        return -1;
    }

    int peek(int stk){
        if(!isEmpty(stk)){
            return arr[top[stk]];
        }
        return -1;
    }

};

int main(){
    NStacks S;
    S.push(1,0);
    S.push(2,1);
    S.push(3,2);
    S.push(4,3);
    S.push(5,4);
    cout<<S.peek(0)<<endl;
    cout<<S.peek(1)<<endl;
    cout<<S.peek(2)<<endl;
    cout<<S.peek(3)<<endl;
    cout<<S.peek(4)<<endl;
}