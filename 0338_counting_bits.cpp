#include <iostream>
#include <vector>
using namespace std;

int pop_count(int n) {
    int count = 0;
    while (n > 0) {
        if ((n & 1) == 1) count++;
        n >>= 1;
    }
    return count;
}

// b == # of bits
// runtime: O(n*b)
// space: O(1)
vector<int> count_bits(int n) {
    vector<int> result;
    for (int i = 0; i <= n; i++) {
        int count = pop_count(i);
        result.push_back(count);
    }
    return result;
}

int pop_count2(int n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}

// USED SOLUTION
// b == # of bits
// runtime: O(n*log(b))
// space: O(1)
vector<int> count_bits2(int n) {
    vector<int> result;
    for (int i = 0; i <= n; i++) {
        int count = pop_count2(i);
        result.push_back(count);
    }
    return result;
}

// USED SOLUTION
// runtime: O(n)
// space: O(n)
vector<int> count_bits3(int n) {
    if (n == 0) return {0};

    vector<int> dp(n + 1, 0);

    int p = 1;  // power of 2
    while (true) {
        for (int i = p; i < p * 2; i++) {
            dp[i] = dp[i - p] + 1;

            if (i == n) return dp;
        }
        p *= 2;
    }
}

int main() {
    vector<int> result = count_bits3(2);  // [0,1,1]
    for (int n : result) {
        cout << n << ' ';
    }
    cout << '\n';

    result = count_bits3(5);  // [0,1,1,2,1,2]
    for (int n : result) {
        cout << n << ' ';
    }
    cout << '\n';
}
