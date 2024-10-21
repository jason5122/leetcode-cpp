/*
n == nums.size()
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size();

        vector<int> nth_index;
        for (int i = 0; i < n; i++) {
            if (nums[i] == x) {
                nth_index.emplace_back(i);
            }
        }

        vector<int> ans;
        for (int q : queries) {
            int nth = q - 1;
            if (nth < nth_index.size()) {
                ans.emplace_back(nth_index[nth]);
            } else {
                ans.emplace_back(-1);
            }
        }
        return ans;
    }
};
