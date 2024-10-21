/*
nums = [10,5,2,6], k = 100
[10,50,100,600]

n == nums.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 0;
        int start = 0;
        int product = 1;
        for (int end = 0; end < n; end++) {
            product *= nums[end];

            while (start <= end && product >= k) {
                product /= nums[start];
                start++;
            }

            if (product < k) {
                ans += end - start + 1;
            }
        }
        return ans;
    }
};
