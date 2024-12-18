/*
USED SOLUTION
n == nums.size()
runtime: O(n*2^n)
space: O(n)

Copying the subsets over takes O(n) time.
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> subset;

    void backtrack(vector<int>& nums, int start) {
        ans.push_back(subset);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;

            subset.push_back(nums[i]);
            backtrack(nums, i + 1);
            subset.pop_back();
        }
    }
};
