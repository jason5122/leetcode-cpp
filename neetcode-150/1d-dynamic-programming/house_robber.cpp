/*
n == nums.size()
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];

        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < size; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return max(dp[size - 1], dp[size - 2]);
    }
};

/*
n == nums.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for (int i = 2; i < size; i++) {
            int curr = max(prev2 + nums[i], prev1);

            prev2 = prev1;
            prev1 = curr;
        }
        return max(prev1, prev2);
    }
};
