/*
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int k = 1; k <= n; k++) {
            if (k - 1 >= 0) dp[k] += dp[k - 1];
            if (k - 2 >= 0) dp[k] += dp[k - 2];
        }
        return dp[n];
    }
};
