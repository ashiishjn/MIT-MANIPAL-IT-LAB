#include <iostream>
using namespace std;
int main(){
    int i, n, val=1;
    cout<<"Enter n:";
    cin>>n;
    for(i=n;i>0;i--){
        val=val*i;
    }
    cout<<val;
    }

