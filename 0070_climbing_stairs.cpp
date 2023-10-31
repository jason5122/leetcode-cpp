#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int climbStairs(int n, unordered_map<int, int>& memo) {
    if (n < 0) return 0;
    if (n <= 1) return 1;
    if (memo.find(n) != memo.end()) return memo[n];

    int result = climbStairs(n - 1, memo) + climbStairs(n - 2, memo);
    memo[n] = result;

    return result;
}

// runtime: O(n)
// space: O(n)
int climbStairs(int n) {
    unordered_map<int, int> memo;
    return climbStairs(n, memo);
}

// runtime: O(n)
// space: O(n)
int climbStairs2(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// runtime: O(n)
// space: O(1)
int climbStairs3(int n) {
    int k = 1;  // n == 0
    int l = 1;  // n == 1

    int next = 1;  // initialized to 1 in case n == 0 or n == 1
    for (int i = 2; i <= n; i++) {
        next = k + l;
        k = l;
        l = next;
    }
    return next;
}

int main() {
    int result = climbStairs3(2);
    cout << result << '\n';  // 2

    result = climbStairs3(3);
    cout << result << '\n';  // 3
}
