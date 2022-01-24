#include  <iostream>
using namespace std;
int c;
int shellSort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        c++;
        for (int i = gap; i < n; i += 1)
        {
            c++;
            int temp = arr[i];
            c++;
            int j;
            c++;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                c++;
                arr[j] = arr[j - gap];
                c++;
            }
            c++;
            arr[j] = temp;
        }
    }
    c++;
    return 0;
}
int main()
{
    int arr[] = {122, 34, 54, 21, 3}, i;
    int n = sizeof(arr)/sizeof(arr[0]);
    shellSort(arr, n);
    cout<<"The step count is "<<c<<endl;
    cout << "Array after sorting: ";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}
