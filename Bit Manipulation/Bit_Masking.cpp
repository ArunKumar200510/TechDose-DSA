#include <iostream>
#include <bitset>
using namespace std;

int setB(int n, int p) {
    return n | (1 << p);
}

int clrB(int n, int p) {
    return n & ~(1 << p);
}

int togB(int n, int p) {
    return n ^ (1 << p);
}

bool isS(int n, int p) {
    return n & (1 << p);
}

int main() {
    int n = 7;
    int p = 1;

    cout << "Original: " << n << " (Binary: " << bitset<8>(n) << ")" << endl;

    int r = setB(n, p);
    cout << "Set: " << r << " (Binary: " << bitset<8>(r) << ")" << endl;

    r = clrB(r, p);
    cout << "Clear: " << r << " (Binary: " << bitset<8>(r) << ")" << endl;

    r = togB(r, p);
    cout << "Toggle: " << r << " (Binary: " << bitset<8>(r) << ")" << endl;

    bool s = isS(r, p);
    cout << "Is set: " << (s ? "Yes" : "No") << endl;

    return 0;
}
