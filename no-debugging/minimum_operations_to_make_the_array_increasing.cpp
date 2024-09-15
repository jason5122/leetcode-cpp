/*
n == nums.size()
k == max_element(nums)
runtime: O(n*k)
space: O(1)
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int curr_max = nums[0];
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            while (nums[i] <= curr_max) {
                nums[i]++;
                ans++;
            }
            curr_max = nums[i];
        }
        return ans;
    }
};

/*
n == nums.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int curr_max = nums[0];
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= curr_max) {
                int new_max = curr_max + 1;

                ans += new_max - nums[i];
                nums[i] = new_max;
            }
            curr_max = nums[i];
        }
        return ans;
    }
};
