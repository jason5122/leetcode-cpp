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

/*
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 0;
        int prev1 = 1;

        for (int k = 1; k <= n; k++) {
            int curr = 0;
            curr += prev1;
            if (k > 1) curr += prev2;

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
