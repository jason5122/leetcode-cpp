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

class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {
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
        int max_count = INT_MAX;
        for (int coin : coins) {
            if (amount - coin >= 0) {
                has_solution = true;
                max_count = min(max_count, backtrack_cached(coins, amount - coin, count + 1));
            }
        }
        return has_solution ? max_count : -1;
    }
};

int main() {
    Solution2 soln;
    vector<int> coins;
    int amount;
    int ans;

    soln = Solution2();
    coins = {1, 2, 5};
    amount = 11;
    ans = soln.coinChange(coins, amount);
    cout << ans << '\n';  // 3

    soln = Solution2();
    coins = {2};
    amount = 3;
    ans = soln.coinChange(coins, amount);
    cout << ans << '\n';  // -1

    soln = Solution2();
    coins = {1};
    amount = 0;
    ans = soln.coinChange(coins, amount);
    cout << ans << '\n';  // 0

    // USED SOLUTION
    soln = Solution2();
    coins = {1};
    amount = 2;
    ans = soln.coinChange(coins, amount);
    cout << ans << '\n';  // 2
}
