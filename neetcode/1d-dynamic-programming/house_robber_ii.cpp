/*
USED SOLUTION
n == nums.size()
runtime: O(2n)
space: O(2n)
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        if (size == 2) return max(nums[0], nums[1]);

        return max(helper(nums, 0, size - 1), helper(nums, 1, size));
    }

private:
    int helper(vector<int>& nums, int start, int end) {
        vector<int> dp(end - start, 0);

        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[1 + start]);

        for (int i = 2 + start; i < end; i++) {
            dp[i - start] = max(dp[i - start - 2] + nums[i], dp[i - start - 1]);
        }
        return dp.back();
    }
};
