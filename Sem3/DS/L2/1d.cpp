#include <iostream>
#include <string.h>
using namespace std;
int main(){
    char a[50], b[50];
    cout<<"Enter the main string:"<<endl;
    gets(a);
    cout<<"Enter the sub string:"<<endl;
    gets(b);
    int n, al, bl;
    cout<<"Enter the location to enter the sub string:";
    cin>>n;
    al=strlen(a);
    bl=strlen(b);
    //SHIFTING ELEMENTS N PLACES TO THE RIGHT BY STEP 'LENGTH(B)'
    for(int i=1;i<=(al-n);i++){
        a[al+bl-i]=a[al-i];
    }
    a[al+bl]='\0';
    //SUBSTITUTING SUBSTRING IN VACATED SPACE
    for(int j=0;j<bl;j++){
        a[n+j]=b[j];
    }
    cout<<a;
}