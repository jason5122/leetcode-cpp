/*
n == nums.size()
runtime: O(n*n!)
space: O(n)

Copying the permutations over takes O(n) time.
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, 0);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> perm;
    unordered_set<int> used;

    void helper(vector<int>& nums, int i) {
        int n = nums.size();
        if (i == n) {
            ans.push_back(perm);
            return;
        }

        for (int k : nums) {
            if (!used.count(k)) {
                perm.push_back(k);
                used.insert(k);
                helper(nums, i + 1);
                perm.pop_back();
                used.erase(k);
            }
        }
    }
};
