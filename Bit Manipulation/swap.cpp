#include <iostream>
using namespace std;

void swa(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

int main() {
    int a = 15, b = 40;
    swa(a, b);
    cout << "After Swapping a: " << a << ", b: " << b << endl;
    return 0;
}
