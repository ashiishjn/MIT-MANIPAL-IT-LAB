#include <iostream>
#include <stack>
using namespace std;

int main(){
    int arr[7]={1,34,23,424,5,342,23};
    int sol[7];
    stack < int > s; 
    s.push(arr[0]);
    sol[0]=-1; 
    for (int i = 1; i < 7; i++) { 
        if(s.empty()){ 
            s.push(arr[i]); 
            continue; 
        } 
        while (!s.empty()&& s.top() < arr[i]) {          
            sol[i]=s.top();
            s.pop();}
        s.push(arr[i]); 
        while (!s.empty()) { 
            sol[i]=-1;
            s.pop(); 
        } 
    }
    for(int i=0;i<7;i++){
        cout<<sol[i]<<" ";
    }
}