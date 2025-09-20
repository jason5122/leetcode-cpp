/*
USED HINT
n == nums.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int invalids = 0;

        const int kInvalid = n + 1;
        auto valid = [n](int i) { return 0 <= i && i < n; };

        for (int i = 0; i < n; i++) {
            if (nums[i] < 1) {
                invalids++;
                nums[i] = kInvalid;
            }
        }

        for (int k : nums) {
            int i = abs(k) - 1;
            if (valid(i) && nums[i] > 0) nums[i] *= -1;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }
        return n - invalids + 1;
    }
};
