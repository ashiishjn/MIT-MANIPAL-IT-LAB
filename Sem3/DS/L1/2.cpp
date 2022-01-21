// Program to implement Non-optimized sorting methods

#include <iostream>
using namespace std;

//N-1 PASSES
void bubbleSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}

// N-1 PASSES
void selectionSort(int a[], int n){
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        swap(a[i],a[min]);
    }
}

// N-1 PASSES
void insertionSort(int a[], int n){
    int key;
    for(int i=1; i<n; i++){
        key = a[i];
        int j=i-1;
        while(a[j]>key && j>=0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++){
        cout<<"\nEnter the element at position "<<i<<":\n";
        cin>>a[i];
        b[i]=a[i];
        c[i]=a[i];
    }
    
    bubbleSort(a,n);
    cout<<endl<<"Bubble Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    selectionSort(b,n);
    cout<<endl<<"Selection Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    insertionSort(c,n);
    cout<<endl<<"Insertion Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<c[i]<<" ";
    }
}