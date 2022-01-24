
#include<bits/stdc++.h>
using namespace std;
int c;
int interpolationSearch(int arr[], int n, int x)
{
    int lo = 0, hi = (n - 1);
    c++;
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        c++;
        if (lo == hi)
        {
            c++;
            if (arr[lo] == x)
            {
                c++;
                return lo;
            }
            c++;
            return -1;
        }
        c++;
        int pos = lo + (((double)(hi - lo) /(arr[hi] - arr[lo])) * (x - arr[lo]));
        c++;
        if (arr[pos] == x)
        {
            c++;
            return pos;
        }
        if (arr[pos] < x)
        {
            c++;
            lo = pos + 1;
        }
        else
        {
            c++;
            hi = pos - 1;
        }
    }
    c++;
    return -1;
}
int main()
{
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 25;
    int index = interpolationSearch(arr, n, x);
    cout<<"The step count is "<<c<<endl;
    if (index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found.";
    return 0;
}
