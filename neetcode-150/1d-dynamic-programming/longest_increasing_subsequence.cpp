/*
dp[i] = dp[j] + 1
where j is the index of max(dp[0..i-1]) and nums[i] > nums[j]

n == nums.size()
runtime: O(n^2)
space: O(n)
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        // Base case.
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            int max_seq = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    max_seq = max(dp[j], max_seq);
                }
            }
            dp[i] = max_seq + 1;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
