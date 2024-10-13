#include <iostream>
using namespace std;

bool find_odd_even(int x) {
    return x & 1;
}

int main() {
    int x = 2;
    cout << x << " is " << (find_odd_even(x) ? "Odd Numebr" : "Even Number") << endl;
    return 0;
}
