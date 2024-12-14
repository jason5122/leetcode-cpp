/*
n == nums.size()
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int n : nums) {
            if (seen.count(n)) return true;
            else seen.insert(n);
        }
        return false;
    }
};
