/*
n == candidates.size()
runtime: O(n*2^n)
space: O(n)

Copying the subsets over takes O(n) time.
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->target = target;
        backtrack(candidates, 0);
        return ans;
    }

private:
    int target;
    vector<vector<int>> ans;
    vector<int> subset;
    int sum = 0;

    void backtrack(vector<int>& nums, int start) {
        if (sum >= target) {
            if (sum == target) ans.push_back(subset);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;

            subset.push_back(nums[i]);
            sum += nums[i];
            backtrack(nums, i + 1);
            subset.pop_back();
            sum -= nums[i];
        }
    }
};
