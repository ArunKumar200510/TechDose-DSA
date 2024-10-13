#include<bits/stdc++.h>

using namespace std;

int isset(int num, int i){
    num >>= i-1;
    return num &1;
}
int main()
{
    int inp;
    cin >> inp;
    cout << isset(inp,2);

}


