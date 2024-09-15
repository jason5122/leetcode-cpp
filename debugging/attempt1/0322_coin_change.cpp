#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
m == amount
n == coins.size()
runtime: O(n^m)
space: O(m)
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        return backtrack(coins, amount, 0);
    }

private:
    int backtrack(vector<int>& coins, int amount, int ans) {
        if (amount == 0) return ans;

        bool has_solution = false;
        int max_ans = INT_MAX;
        for (int coin : coins) {
            if (amount - coin >= 0) {
                has_solution = true;
                max_ans = min(max_ans, backtrack(coins, amount - coin, ans + 1));
            }
        }
        return has_solution ? max_ans : -1;
    }
};

// WRONG
class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<>());
        return backtrack(coins, amount, 0);
    }

private:
    unordered_map<int, int> cache;

    int backtrack_cached(vector<int>& coins, int amount, int count) {
        if (!cache.count(amount)) {
            int ans = backtrack(coins, amount, count);
            cache[amount] = ans;
        }
        return cache[amount];
    }

    int backtrack(vector<int>& coins, int amount, int count) {
        if (amount == 0) return count;

        bool has_solution = false;
        int min_count = INT_MAX;
        for (int coin : coins) {
            if (amount - coin >= 0) {
                has_solution = true;
                min_count = min(min_count, backtrack_cached(coins, amount - coin, count + 1));
            }
        }
        return has_solution ? min_count : -1;
    }
};

// WRONG
class Solution3 {
public:
    int coinChange(vector<int>& coins, int amount) {
        queue<long> q;
        q.push({0});

        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                long sum = q.front();
                q.pop();

                if (sum == amount) {
                    return depth;
                }

                for (int coin : coins) {
                    if (sum + coin <= amount) {
                        q.push({sum + coin});
                    }
                }
            }
            depth++;
        }
        return -1;
    }
};

/*
m == amount
n == coins.size()
runtime: O(m*n)
space: O(m)
*/
class Solution4 {
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

int main() {
    Solution4 soln;
    vector<int> coins;
    int amount;
    int ans;

    soln = Solution4();
    coins = {1, 2, 5};
    amount = 11;
    ans = soln.coinChange(coins, amount);
    cout << ans << '\n';  // 3

    soln = Solution4();
    coins = {2};
    amount = 3;
    ans = soln.coinChange(coins, amount);
    cout << ans << '\n';  // -1

    soln = Solution4();
    coins = {1};
    amount = 0;
    ans = soln.coinChange(coins, amount);
    cout << ans << '\n';  // 0

    // USED SOLUTION
    soln = Solution4();
    coins = {1};
    amount = 2;
    ans = soln.coinChange(coins, amount);
    cout << ans << '\n';  // 2

    // USED SOLUTION
    soln = Solution4();
    coins = {1, 2147483647};
    amount = 2;
    ans = soln.coinChange(coins, amount);
    cout << ans << '\n';  // 2

    // USED SOLUTION
    soln = Solution4();
    coins = {1, 2, 5};
    amount = 100;
    ans = soln.coinChange(coins, amount);
    cout << ans << '\n';  // 20

    // USED SOLUTION
    soln = Solution4();
    coins = {2, 5, 10, 1};
    amount = 27;
    ans = soln.coinChange(coins, amount);
    cout << ans << '\n';  // 4
}
