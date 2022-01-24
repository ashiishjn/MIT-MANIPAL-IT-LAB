#include <iostream>
using namespace std;
int x;
void max_container(int wt[], int c)
{
    int count = 0;
    int cap=0,pos;
    x++;
    x++;
    for(int j=0;j<8;j++)
    {
        x++;
        int min=100;
        x++;
        for(int i=0;i<8;i++)
        {
            x++;
            if(wt[i]<min && wt[i]!=-1)
            {
                x++;
                x++;
                min=wt[i];
                pos=i;
            }
        }
        x++;
        cap+=wt[pos];
        if(cap<=c)
        {
            x++;
            count++;
            x++;
            wt[pos]=-1;
        }
        else
        {
            x++;
            break;
        }
    }
    x++;
    cout<<"Maximum no. of containers loaded is "<<count;
}
int main()
{
    int wt[]={5,8,3,8,18,3,7,6};
    int c = 40;
    max_container(wt,c);
    cout<<"\nThe step count is "<<x;
    return 0;
}
