#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        if (n == 1) {
            return countSingleDigitNumbersDivisibleByK(k);
        }

        using ll = long long;
        ll start = pow(10, (n / 2) - 1);
        ll end = pow(10, (n / 2)) - 1;

        set<string> validNumbers;
        for (ll i = start; i <= end; ++i) {
            ll cur = i;
            if (n % 2 == 1) {
                processOddLengthNumbers(cur, k, validNumbers);
            } else {
                processEvenLengthNumbers(cur, k, validNumbers);
            }
        }

        return calculateValidCounts(validNumbers, n);
    }

private:
    long long countSingleDigitNumbersDivisibleByK(int k) {
        int count = 0;
        for (int i = 1; i < 10; ++i) {
            if (i % k == 0) {
                ++count;
            }
        }
        return count;
    }

    void processOddLengthNumbers(long long cur, int k, set<string>& validNumbers) {
        string str = to_string(cur);
        reverse(str.begin(), str.end());

        for (long long j = 0; j < 10; ++j) {
            long long val = cur * 10 + j;
            for (char p : str) {
                val = (val * 10) + (p - '0');
            }
            if (val % k == 0) {
                string sortedVal = to_string(val);
                sort(sortedVal.begin(), sortedVal.end());
                validNumbers.insert(sortedVal);
            }
        }
    }

    void processEvenLengthNumbers(long long cur, int k, set<string>& validNumbers) {
        string str = to_string(cur);
        reverse(str.begin(), str.end());

        long long val = cur;
        for (char p : str) {
            val = (val * 10) + (p - '0');
        }
        if (val % k == 0) {
            string sortedVal = to_string(val);
            sort(sortedVal.begin(), sortedVal.end());
            validNumbers.insert(sortedVal);
        }
    }

    long long calculateValidCounts(const set<string>& validNumbers, int n) {
        vector<long long> factorials(11, 0);
        factorials[0] = 1;
        for (int i = 1; i <= 10; ++i) {
            factorials[i] = factorials[i - 1] * i;
        }

        long long totalCount = 0;
        for (const string& str : validNumbers) {
            totalCount += getValidCounts(str, factorials, n);
        }

        return totalCount;
    }

    long long getValidCounts(const string& str, const vector<long long>& factorials, int n) {
        long long count = factorials[n];
        vector<int> frequency(10, 0);

        for (char ch : str) {
            frequency[ch - '0'] += 1;
        }

        for (int i = 0; i < 10; ++i) {
            count /= factorials[frequency[i]];
        }

        if (frequency[0]) {
            int p = n - 1;
            long long decrement = factorials[p];
            frequency[0] -= 1;
            for (int i = 0; i < 10; ++i) {
                decrement /= factorials[frequency[i]];
            }
            frequency[0] += 1;
            count -= decrement;
        }

        return count;
    }
};

int main() {
    Solution solution;
    int n = 5; // Example value for n
    int k = 6; // Example value for k
    cout << "Count of good integers: " << solution.countGoodIntegers(n, k) << endl;

    return 0;
}
