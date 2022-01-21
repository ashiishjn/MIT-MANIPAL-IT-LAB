// Program to implement Insertion Sort

#include <iostream>
using namespace std;
void insertionSort(int array[], int size){
  for(int step=1; step<size; step++){
    int key = array[step];
    int j=step-1;
    while(key<array[j] && j>=0){
        array[j+1] = array[j];
        --j;
    }
    array[j+1]=key;
    for(int i=0;i<size;i++)
        cout<<array[i]<<" ";
    cout<<endl;
  }
}

int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"\nEnter the element at position "<<i<<":\n";
        cin>>a[i];
    }
    insertionSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}