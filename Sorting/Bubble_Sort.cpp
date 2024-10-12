#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[],int size = 5)
{

    cout << "Before Sorted" << '\n';
    for(int i = 0;i < size;i++)
    {
        cout << arr[i] << " ";
    }
    for(int i = size-1;i > -1;i--)
    {
        bool swapped = false;
        for(int j = 0;j < i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
            if(!swapped) break;
    }
    }
    cout << '\n' << "After Sorted"<<'\n';
    for(int i = 0;i < size;i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[5] = {8,4,7,1,5};
    bubble_sort(arr);
    return 0;
}