/*
n == candidates.size()
m == min # in candidates
t = target
runtime: O(n^(t/m))
space: O(t/m)

Copying the combinations over takes O(n) time.
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, 0, target);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> comb;

    void backtrack(vector<int>& nums, int start, int remaining) {
        if (remaining <= 0) {
            if (remaining == 0) ans.push_back(comb);
            return;
        }
        if (start >= nums.size()) return;

        for (int i = start; i < nums.size(); i++) {
            comb.push_back(nums[i]);
            backtrack(nums, i, remaining - nums[i]);
            comb.pop_back();
        }
    }
};
