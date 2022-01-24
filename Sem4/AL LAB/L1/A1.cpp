#include <iostream>

using namespace std;

int c;

int del_substr(char a[],char d[])
{
    int n,p,i,j,cnt=0;
    c++;
    for(n=0;a[n]!='\0';n++)
    {
        c++;
    }
    for(p=0;d[p]!='\0';p++)
    {
        c++;
    }
    for(i=0;i<n;i++)
    {
        c++;
        int f=0;
        c++;
        c++;
        if(a[i-1]==32||i==0)
        {
            for(j=0;d[j]!='\0';j++)
            {
                c++;
                c++;
                if(a[j+i]!=d[j]&&a[j+i]+32!=d[j]&&a[j+i]-32!=d[j])
                {
                    c++;
                    f=1;
                    c++;
                    break;
                }
            }
            c++;
            if(f==0)
            {
                c++;
                cnt++;
                c++;
                i+=p;
            }
        }
    }
    c++;
    return cnt;
}

int main()
{
    int cnt;
    char a[1000],d[50];
    cout<<"Enter string and substring\n";
    fflush(stdin);
    cin.get(a,1000);
    fflush(stdin);
    cin.get(d,50);
    cnt=del_substr(a,d);
    cout<<"The step count is "<<c<<endl;
    cout<<"The count is "<<cnt;
    return 0;
}
