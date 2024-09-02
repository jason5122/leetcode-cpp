/*
NOT DYNAMIC PROGRAMMING
n == nums.size()
runtime: O(2^n)
space: O(n)
*/
class Solution {
    vector<int> nums;
    int target;

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;
        return helper(0, 0);
    }

private:
    int helper(int i, int total) {
        if (i == nums.size()) return total == target;

        return helper(i + 1, total - nums[i]) + helper(i + 1, total + nums[i]);
    }
};

/*
NOT DYNAMIC PROGRAMMING
n == nums.size()
k == max_value - min_value
runtime: O(n*k)
space: O(n*k)
*/
class Solution {
    vector<int> nums;
    int target;
    unordered_map<int, unordered_map<int, int>> memo;

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;
        return helper(0, 0);
    }

private:
    int helper(int i, int total) {
        if (i == nums.size()) return total == target;
        if (memo.count(i) && memo[i].count(total)) return memo[i][total];

        return memo[i][total] = helper(i + 1, total - nums[i]) + helper(i + 1, total + nums[i]);
    }
};

/*
USED SOLUTION

dp[i][j] = ???

n == nums.size()
k == 2 * sum of nums + 1
runtime: O(n*k)
space: O(n*k)
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = reduce(nums.begin(), nums.end());
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));

        // Base case.
        dp[0][nums[0] + sum] = 1;
        dp[0][-nums[0] + sum] += 1;

        // Fill out sub-problems.
        for (int i = 1; i < n; i++) {
            for (int j = -sum; j <= sum; j++) {
                if (dp[i - 1][j + sum] > 0) {
                    dp[i][j + nums[i] + sum] += dp[i - 1][j + sum];
                    dp[i][j - nums[i] + sum] += dp[i - 1][j + sum];
                }
            }
        }

        return abs(target) > sum ? 0 : dp[n - 1][target + sum];
    }
};
