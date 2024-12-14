/*
n == nums.size()
runtime: O(3n)
space: O(2n)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> exclude_right(size);
        vector<int> exclude_left(size);

        int product = 1;
        for (int i = 0; i < size; i++) {
            product *= nums[i];
            exclude_right[i] = product;
        }
        product = 1;
        for (int i = size - 1; i >= 0; i--) {
            product *= nums[i];
            exclude_left[i] = product;
        }

        vector<int> ans(size);
        for (int i = 0; i < size; i++) {
            int left = i > 0 ? exclude_right[i - 1] : 1;
            int right = i < size - 1 ? exclude_left[i + 1] : 1;
            ans[i] = left * right;
        }
        return ans;
    }
};

/*
FOLLOW UP

n == nums.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();

        vector<int> exclude_left(nums);

        int product = 1;
        for (int i = size - 1; i >= 0; i--) {
            product *= exclude_left[i];
            exclude_left[i] = product;
        }

        product = 1;
        for (int i = 0; i < size; i++) {
            int left = i > 0 ? product : 1;
            int right = i < size - 1 ? exclude_left[i + 1] : 1;
            exclude_left[i] = left * right;

            product *= nums[i];
        }
        return exclude_left;
    }
};
