/*
n == nums.size()
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complements;
        for (int i = 0; i < nums.size(); i++) {
            if (complements.count(nums[i])) return {complements[nums[i]], i};
            else complements[target - nums[i]] = i;
        }
        return {-1, -1};
    }
};
