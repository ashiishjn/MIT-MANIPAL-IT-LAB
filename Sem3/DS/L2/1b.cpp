#include <iostream>
using namespace std;
int main(){
    char a[50];
    cout<<"Enter the string 1:";
    cin>>a;
    char b[50];
    cout<<"Enter the string 2:";
    cin>>b;
    int m;
    for(m=0;a[m]!='\0';m++);
    int n;
    for(n=0;b[n]!='\0';n++){
        a[n+m]=b[n];
    }
    a[n+m+1]='\0';
    cout<<a;
}
