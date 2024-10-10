/*
USED SOLUTION
n == nums.size()
runtime: O(n*lg(n))
space: O(1)
*/
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                int new_val = nums[i - 1] + 1;
                ans += new_val - nums[i];
                nums[i] = new_val;
            }
        }
        return ans;
    }
};
