// Program to implement the addition of two matrices

#include <iostream>
using namespace std;
int main(){
    int m,n;
    cout<<"Enter the size of the array(m x n):";
    cin>>m>>n;
    int a[m][n],b[m][n],c[m][n];
    for (int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<"Enter the element at A["<<i<<"]["<<j<<"]:";
            cin>>a[i][j];
        }
        cout<<endl;
    }
    for (int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<"Enter the element at B["<<i<<"]["<<j<<"]:";
            cin>>b[i][j];
        }
        cout<<endl;
    }
    for (int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            c[i][j]=(a[i][j]>b[i][j])?a[i][j]:b[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}