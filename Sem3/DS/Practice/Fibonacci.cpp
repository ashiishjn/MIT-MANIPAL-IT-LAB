#include <iostream>
using namespace std;
int main(){
    int i,a,b, f=1, n;
    cout<<"Enter n:";
    cin>>n;
    a=0;
    cout<<a<<"\n";
    b=1;
    cout<<b<<"\n";
    for(i=0;i<n-2;i++){
        f=a+b;
        cout<<f<<"\n";
        a=b;
        b=f;

    }
    }
