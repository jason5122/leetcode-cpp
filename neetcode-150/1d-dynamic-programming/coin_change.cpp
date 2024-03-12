/*
m == amount
n == coins.size()
runtime: O(m*n)
space: O(m)
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int coin : coins) {
            if (coin < amount) dp[coin] = 1;
        }

        for (int k = 1; k <= amount; k++) {
            for (int coin : coins) {
                if (k - coin >= 0 && dp[k - coin] != -1) {
                    if (dp[k] == -1) {
                        dp[k] = dp[k - coin] + 1;
                    } else {
                        dp[k] = min(dp[k - coin] + 1, dp[k]);
                    }
                }
            }
        }
        return dp[amount];
    }
};
