/*
n == nums.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int jump = nums[i];
        while (i < n - 1) {
            int old_i = i;

            for (int j = i; j <= min(i + jump, n - 1); j++) {
                if (j + nums[j] > i + jump) {
                    i = j;
                    jump = nums[j];
                }
            }

            if (i + jump >= n - 1) return true;
            if (i == old_i) return false;
        }
        return true;
    }
};
