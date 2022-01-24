    #include <iostream>
    using namespace std;
    int c;
    void insertionsort(int a[],int n)
    {
        int i,j,k;
        c++;
        for(i=1;i<n;i++)
        {
            c++;
            k=a[i];
            c++;
            for(j=i-1;j>=0 && a[j]>k;j--)
            {
                c++;
                a[j+1]=a[j];
                c++;
            }
            c++;
            a[j+1]=k;
        }
    }
    int main()
    {
        int i,j,k,n;
        cout<<"Enter the length of array";
        cin>>n;
        int a[n];
        cout<<"Enter the elements in the array";
        for(i=0;i<n;i++)
            cin>>a[i];
        insertionsort(a,n);
        cout<<"The step count is "<<c<<endl;
        for(i=0;i<n;i++)
            cout<<" "<<a[i];
        return 0;
    }
