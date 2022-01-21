#include <iostream>
using namespace std;
int main(){
    int i, j, k, choice, m, n, p, q, r, s;
    int a[50][50], b[50][50], c[50][50];
    cout<<"Select your operation:\n1.Addition\n2.Subtraction\n3.Multiplication\n";
    cin>>choice;
    cout<<"Enter the rows of A:";
    cin>>m;
    cout<<"Enter the columns of A:";
    cin>>n;
    cout<<"Enter the rows of B:";
    cin>>p;
    cout<<"Enter the columns of B:";
    cin>>q;
    if (choice==1){
        if (m!=p && n!=q){
            cout<<"Matrix size mismatch!";
        }
        else{
            for(i=0;i<m;i++){
                for(j=0;j<n;j++){
                    cout<<"Enter A["<<i<<"]["<<j<<"]:";
                    cin>>a[i][j];}}
            for(i=0;i<m;i++){
                for(j=0;j<n;j++){
                    cout<<"Enter B["<<i<<"]["<<j<<"]:";
                    cin>>b[i][j];}}
            for(i=0;i<m;i++){
                for(j=0;j<n;j++){
                        c[i][j]=a[i][j]+b[i][j];
                        cout<<c[i][j]<<" ";}
                cout<<"\n";}}}
    else if (choice==2){
        if (m!=p && n!=q){
            cout<<"Matrix size mismatch!";
        }
        else{
            for(i=0;i<m;i++){
                for(j=0;j<n;j++){
                    cout<<"Enter A["<<i<<"]["<<j<<"]:";
                    cin>>a[i][j];}}
            for(i=0;i<m;i++){
                for(j=0;j<n;j++){
                    cout<<"Enter B["<<i<<"]["<<j<<"]:";
                    cin>>b[i][j];}}
            for(i=0;i<m;i++){
                for(j=0;j<n;j++){
                        c[i][j]=a[i][j]-b[i][j];
                        cout<<c[i][j]<<" ";}
                cout<<"\n";}}}
    else if (choice==3){
        if (n!=p){
            cout<<"Matrix size mismatch!";}
        else{
            for(i=0;i<m;i++){
                for(j=0;j<n;j++){
                    cout<<"Enter A["<<i<<"]["<<j<<"]:";
                    cin>>a[i][j];}}
            for(i=0;i<p;i++){
                for(j=0;j<q;j++){
                    cout<<"Enter B["<<i<<"]["<<j<<"]:";
                    cin>>b[i][j];}}
            for(i=0;i<m;i++){
                for(j=0;j<q;j++){
                    c[i][j]=0;
                    for(k=0;k<n;k++){
                        c[i][j]+=a[i][k]*b[k][j];}
                cout<<c[i][j]<<" ";}
                cout<<"\n";}}}
    else{
        cout<<"Invalid Choice";
        return 0;}
}
