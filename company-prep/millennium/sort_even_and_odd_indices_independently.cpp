/*
n == nums.size()
runtime: O(n*lg(n))
space: O(n)
*/
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();

        vector<int> even;
        vector<int> odd;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                even.push_back(nums[i]);
            } else {
                odd.push_back(nums[i]);
            }
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end(), greater<>{});

        int even_idx = 0;
        int odd_idx = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                ans.push_back(even[even_idx++]);
            } else {
                ans.push_back(odd[odd_idx++]);
            }
        }
        return ans;
    }
};
