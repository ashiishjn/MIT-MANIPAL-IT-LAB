// Program to implement Linear Search

#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"\nEnter the element at position "<<i<<":\n";
        cin>>a[i];
    }
    cout<<"Enter the element to search for:";
    int elem;
    cin>>elem;
    int f=0;
    for(int i=0;i<n;i++){
        if(elem==a[i]){
            cout<<"Element found at "<<i;
            f=1;
            return 0;
            }
        }

    if (f == 0){
        cout<<"\nElement not found\n";
    }
    return 0;
}