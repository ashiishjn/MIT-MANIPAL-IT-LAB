#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

class Student{
    private:
        char name[50];
        char grade;
        int roll;
    public:
        void reader(Student s[], int n){
            for(int i=0;i<n;i++){
                cout<<"Enter the roll no:";
                cin>>(s[i].roll);
                fflush(stdin);
                cout<<"Enter the name:";
                gets(s[i].name);
                cout<<"Enter the grade:";
                cin>>(s[i].grade);
            }
        }
        void printer(Student s[], int n){
            for(int i=0;i<n;i++){
                cout<<endl<<"Student "<<i+1<<endl;
                cout<<"Roll No.: "<<s[i].roll<<endl;
                cout<<"Name: "<<s[i].name<<endl;
                cout<<"Grade: "<<s[i].grade<<endl;
            }
        }
        void sort(Student s[],int n){
            Student temp;
            int min;
            for(int i=0;i<n;i++){
                min=i;
                for(int j=i+1;j<n;j++){
                    if(s[j].roll<s[min].roll){
                        min=j;
                    }
                }
                temp=s[i];
                s[i]=s[min];
                s[min]=temp;
                }
        }
};


int main(){
    int n;
    cout<<"Enter the number of students:";
    cin>>n;
    fflush(stdin);
    Student s[n], a;
    a.reader(s,n);
    a.sort(s,n);
    a.printer(s,n);
    return 0;
}  