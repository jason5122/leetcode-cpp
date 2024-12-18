/*
n == nums.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int mask = 0;
        for (int k : nums) {
            mask ^= k;
        }
        return mask;
    }
};
