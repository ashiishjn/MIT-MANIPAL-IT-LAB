// Program to manually find the length of a string using a character array

#include <iostream>
using namespace std;
int main(){
    char c[50];
    cout<<"Enter the string:";
    cin>>c;
    int i;
    for(i=0;c[i]!='\0';i++);
    cout<<"The size of the string is "<<i;
}