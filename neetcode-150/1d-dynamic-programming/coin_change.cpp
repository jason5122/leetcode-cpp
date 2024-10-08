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

/*
k = amount
dp[k] = dp[k - coin] + 1

n == amount
coins == coins.size()
runtime: O(n*coins)
space: O(n*coins)
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        int n = amount;
        vector<int> dp(n + 1, -1);

        // Base case.
        for (int coin : coins) {
            if (coin <= amount) {
                dp[coin] = 1;
            }
        }

        // Fill out sub-problems.
        for (int k = 0; k <= n; k++) {
            for (int coin : coins) {
                if (coin <= k && dp[k - coin] != -1) {
                    if (dp[k] == -1) {
                        dp[k] = dp[k - coin] + 1;
                    } else {
                        dp[k] = min(dp[k - coin] + 1, dp[k]);
                    }
                }
            }
        }

        return dp[n];
    }
};
