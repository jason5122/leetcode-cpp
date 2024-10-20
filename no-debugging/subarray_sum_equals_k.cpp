/*
nums = [1,1,1], k = 2
[1,2,3]

nums = [1,2,3], k = 3
[1,3,6]

n == nums.size()
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefix(n, 0);
        partial_sum(nums.begin(), nums.end(), prefix.data());

        unordered_map<int, int> complement;
        complement[0] = 1;

        int ans = 0;
        for (int a : prefix) {
            ans += complement[a - k];
            complement[a]++;
        }
        return ans;
    }
};
