/*
USED SOLUTION (in a hurry)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i];
            unordered_map<int, int> hm;
            unordered_set<int> seen;
            for (int j = i + 1; j < n; j++) {
                // Ignore duplicates.
                if (seen.count(nums[j])) continue;

                if (hm.count(nums[j])) {
                    int k = hm[nums[j]];
                    ans.push_back({nums[i], nums[j], nums[k]});
                    seen.insert(nums[j]);
                } else {
                    int complement = target - nums[j];
                    hm[complement] = j;
                }
            }
        }
        return ans;
    }
};
