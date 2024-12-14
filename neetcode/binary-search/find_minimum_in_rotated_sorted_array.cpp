/*
USED SOLUTION

6 7 1 2 3 4 5

4 5 6 7 8 1 2 3

n == nums.size()
runtime: O(lg(n))
space: O(1)
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int l = 0, r = n - 1;

        if (nums[r] > nums[0]) return nums[0];  // no rotation

        while (l <= r) {
            int m = (l + r) / 2;

            if (nums[m] > nums[m + 1]) return nums[m + 1];
            if (nums[m - 1] > nums[m]) return nums[m];

            if (nums[m] > nums[0]) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
};
