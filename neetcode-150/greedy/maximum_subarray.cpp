/*
NOT GREEDY
n == nums.size()
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        // Base case.
        dp[0] = nums[0];

        // Fill in sub-problems.
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1], 0) + nums[i];
        }

        return *max_element(dp.begin(), dp.end());
    }
};

/*
n == nums.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum = max(sum, 0) + nums[i];

            max_sum = max(sum, max_sum);
        }
        return max_sum;
    }
};
