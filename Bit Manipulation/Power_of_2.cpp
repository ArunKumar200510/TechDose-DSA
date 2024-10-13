#include<bits/stdc++.h>

using namespace std;

bool ispow(int n)
{
    return (n & n-1) == 0;
}
int main()
{
    int inp;
    cin >> inp;
    if(ispow(inp))
    {
        cout << "Yes, it is";
    }
    else
    {
        cout << "No, its not";
    }
}
