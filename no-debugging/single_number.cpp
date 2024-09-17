/*
n == nums.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int k : nums) {
            ans ^= k;
        }
        return ans;
    }
};
