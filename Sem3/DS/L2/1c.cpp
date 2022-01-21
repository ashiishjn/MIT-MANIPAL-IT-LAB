// Program to compare two strings

#include <iostream>
using namespace std;
int main(){
    char a[50],b[50];
    int i;
    cout<<"Enter String 1:";
    cin>>a;
    cout<<"Enter String 2:";
    cin>>b;
    for (i=0;a[i]==b[i]&& a[i]!='\0';i++);
    if(a[i]<b[i]){
        cout<<"String 1 is less than 2";
    }
    else if (a[i]>b[i]){
        cout<<"String 1 is greater than 2";
    }
    else{
        cout<<"String 1 is equal to String 2";
    }
    
}
