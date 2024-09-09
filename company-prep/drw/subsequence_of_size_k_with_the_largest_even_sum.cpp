/*
USED SOLUTION
n == nums.size()
runtime: O(n*lg(n))
space: O(1)
*/
class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>{});

        long long sum = accumulate(nums.begin(), nums.begin() + k, 0LL);
        if (sum % 2 == 0) {
            return sum;
        }

        // Find smallest even/odd number in nums[0:k]...
        int min_k[2] = {INT_MAX, INT_MAX};
        for (int i = 0; i < k; i++) {
            bool is_odd = nums[i] % 2;
            min_k[is_odd] = min(min_k[is_odd], nums[i]);
        }
        // ...and replace it with the largest even/odd (opposite) number in nums[k:].
        long long new_sum = -1;
        for (int i = k; i < nums.size(); i++) {
            bool is_odd = nums[i] % 2;
            new_sum = max(sum - min_k[!is_odd] + nums[i], new_sum);
        }
        return new_sum;
    }
};
