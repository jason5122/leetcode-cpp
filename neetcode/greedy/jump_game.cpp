/*
USED TEST CASE
nums = [0,2,3]

n == nums.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int max_idx = 0;
        for (int i = 0; i < n - 1; i++) {
            if (max_idx < i) return false;

            max_idx = max(i + nums[i], max_idx);
        }
        return max_idx >= n - 1;
    }
};
