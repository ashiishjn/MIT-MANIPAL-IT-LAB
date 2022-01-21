// Program to implement QuickSort
#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int arr[],int beg, int end){
    int loc, left, right;
    bool sorted;
    sorted=false;
    loc=left=beg;
    right=end;
    static int pass=1;
    while(!sorted){
        while(loc!=right && arr[loc]<=arr[right])
            right--;
        if(loc==right)
            sorted=true;
        else if(arr[loc]>arr[right]){
            swap(&arr[loc],&arr[right]);
            loc=right;
        }
        //This block only runs if the right side is sorted
        if(!sorted){
            while(arr[loc]>=arr[left] && loc!=left)
                left++;
            if(loc==left)
                sorted=true;
            else if(arr[loc]<arr[left]){
                swap(&arr[loc],&arr[left]);
                loc = left;
            }
        }
        pass++;
    }
    return loc;
}

void QuickSort(int arr[],int beg, int end){
    int loc;
    if(beg<end){
        loc=partition(arr,beg,end);
        QuickSort(arr,beg, loc-1);
        QuickSort(arr,loc+1,end);
    }
}

int main(){
    int arr[]={27,10,36,18,25,45};
    print(arr,6);
    QuickSort(arr,0,5);
    print(arr,6);
}