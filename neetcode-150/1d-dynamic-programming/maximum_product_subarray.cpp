/*
NOT DYNAMIC PROGRAMMING
n == nums.size()
runtime: O(n^2)
space: O(1)
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int max_product = INT_MIN;
        for (int i = 0; i < n; i++) {
            int product = 1;
            for (int j = i; j < n; j++) {
                product *= nums[j];

                max_product = max(product, max_product);
            }
        }
        return max_product;
    }
};

/*
USED SOLUTION

dp[i] = max(k, curr_max * k, curr_min * k)

In addition to recording `curr_max`, we record `curr_min` to track negative chains.

n == nums.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int curr_max = nums[0];
        int curr_min = nums[0];

        int ans = curr_max;

        // Fill in sub-problems.
        for (int i = 1; i < n; i++) {
            int k = nums[i];

            std::initializer_list<int> arr = {k, curr_max * k, curr_min * k};
            curr_max = max(arr);
            curr_min = min(arr);

            ans = max(curr_max, ans);
        }

        return ans;
    }
};
