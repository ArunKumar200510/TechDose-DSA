#include<bits/stdc++.h>

using namespace std;

int set_b(int num, int i){
    return num | (1 << (i-1));
}
int main()
{
    int inp;
    cin >> inp;
    cout << set_b(inp,2);

}
