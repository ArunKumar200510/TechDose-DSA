
#include <iostream>
#include <vector>
using namespace std;

void sub(vector<int>& arr) {
    int n = arr.size();
    int cnt = 1 << n;

    for (int i = 0; i < cnt; i++) {
        vector<int> subset;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset.push_back(arr[j]);
            }
        }
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    sub(arr);
    return 0;
}
