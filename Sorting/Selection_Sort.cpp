#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int size = 5)
{
    cout << "Befor Sorted" << '\n';
    for(int i = 0;i < size;i++)
    {
        cout << arr[i] << " ";
    }
    for(int i = 0;i < size-2;i++)
    {
        int ind = i;
        for(int j = i+1;j < size-1;j++)
        {
            if(arr[j] < arr[ind])
            {
                ind = j;
            }
        }
        swap(arr[i],arr[ind]);
    }
    cout << "After Sorted"<<'\n';
    for(int i = 0;i < size;i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[5] = {8,4,7,1,5};
    selection_sort(arr);
    return 0;
}