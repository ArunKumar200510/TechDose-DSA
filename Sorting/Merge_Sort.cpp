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

void merge(int arr[],int low,int mid, int high)
{
    vector<int> res;
    int left = low;
    int right = mid + 1;
    while(left <= mid && right <= high)
    {
        if(arr[left] < arr[right])
        {
            res.push_back(arr[left]);
            left += 1;
        }
        else
        {
            res.push_back(arr[right]);
            right += 1;
        }
    }
    while(left <= mid)
    {
        res.push_back(arr[left]);
        left += 1;
    }
    while(right <= high)
    {
        res.push_back(arr[right]);
        right += 1;
    }
    for(int i = low; i <= high;i++)
    {
        arr[i] = res[i - low];
    }
}

void merge_sort(int arr[],int low, int high){
    if(low >= high) return;
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr,low,mid,high);

}

int main()
{
    int arr[5] = {8,4,7,1,5};
    cout << "Before Sorted \n";
    display(arr);
    merge_sort(arr,0,4);
    cout << "\n After Sorted \n";
     display(arr);
    return 0;
}