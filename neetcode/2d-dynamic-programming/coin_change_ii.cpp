/*
USED SOLUTION
NOT DYNAMIC PROGRAMMING
n == coins.size()
runtime: O(n*amount)
space: O(n*amount)
*/
class Solution {
    vector<int> coins;
    vector<vector<int>> memo;

public:
    int change(int amount, vector<int>& coins) {
        this->coins = coins;
        memo = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -1));
        return helper(0, amount);
    }

private:
    int helper(int i, int amount) {
        if (amount == 0) return 1;
        if (i == coins.size()) return 0;
        if (memo[i][amount] != -1) return memo[i][amount];

        if (coins[i] > amount) {
            memo[i][amount] = helper(i + 1, amount);
        } else {
            memo[i][amount] = helper(i + 1, amount) + helper(i, amount - coins[i]);
        }
        return memo[i][amount];
    }
};

/*
USED SOLUTION

if (coins[i] > j) {
    dp[i][j] = dp[i + 1, j]
} else {
    dp[i][j] = dp[i + 1, j] + dp[i, j - coins[i]]
}

n == coins.size()
runtime: O(n*amount)
space: O(n*amount)
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        // Base case.
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        // Fill in sub-problems.
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i] > j) {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - coins[i]];
                }
            }
        }

        return dp[0][amount];
    }
};
