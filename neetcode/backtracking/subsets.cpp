/*
n == nums.size()
runtime: O(n*2^n)
space: O(n)

Copying the subsets over takes O(n) time.
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(nums, 0);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> subset;

    void helper(vector<int>& nums, int i) {
        if (i == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // Exclude current element.
        helper(nums, i + 1);

        // Include current element, then backtrack.
        subset.push_back(nums[i]);
        helper(nums, i + 1);
        subset.pop_back();
    }
};

/*
USED SOLUTION
n == nums.size()
runtime: O(n*2^n)
space: O(n)

Copying the subsets over takes O(n) time.
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> subset;

    void backtrack(vector<int>& nums, int start) {
        ans.push_back(subset);

        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            backtrack(nums, i + 1);
            subset.pop_back();
        }
    }
};
