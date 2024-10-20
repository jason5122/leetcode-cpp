/*
nums = [4,5,0,-2,-3,1], k = 5
[4,9,9,7,4,5]

nums = [5,5,5], k = 5

nums = [5], k = 9

USED TEST CASE
nums = [-1,2,9], k = 2
[-1,1,10]

n == nums.size()
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> complement;

        vector<int> prefix(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            prefix[i] = sum;
        }

        int ans = 0;
        for (int a : prefix) {
            int mod = positive_modulo(a, k);
            ans += complement[mod];
            if (mod == 0) ans++;  // Count self.

            complement[mod]++;
        }
        return ans;
    }

private:
    inline int positive_modulo(int i, int n) {
        return (i % n + n) % n;
    }
};
