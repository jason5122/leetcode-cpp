class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> chosen;

    void backtrack(vector<int>& nums, int remaining) {
        if (remaining == 0) {
            ans.push_back(chosen);
            return;
        }

        for (int k : nums) {
            if (!chosen.empty() && k < chosen.back()) continue;

            if (remaining >= k) {
                chosen.push_back(k);
                backtrack(nums, remaining - k);
                chosen.pop_back();
            }
        }
    }
};
