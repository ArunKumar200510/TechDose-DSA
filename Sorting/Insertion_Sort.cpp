#include<bits/stdc++.h>
using namespace std;

void display(int arr[])
{
    int size = 5;
    for(int i = 0;i < size;i++)
    {
        cout << arr[i] << " ";
    }
}

void insertion_sort(int arr[],int size = 5)
{
    cout << "Befor Sorted" << '\n';
    display(arr);
    
    for(int i = 0;i < size ;i++)
    {
        int j = i;
        while(j >= 0 && arr[j-1] > arr[j])
        {
            swap(arr[j],arr[j-1]);
            j-= 1;
        }
    }

    cout << "\nAfter Sorted"<<'\n';
    display(arr);

}

int main()
{
    int arr[5] = {8,4,7,1,5};
    insertion_sort(arr);
    return 0;
}