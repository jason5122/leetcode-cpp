/*
n == nums.size()
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nodes(nums.begin(), nums.end());

        int ans = 0;
        while (!nodes.empty()) {
            int k = *nodes.begin();
            nodes.erase(k);

            int count = 1;
            int prev = k - 1;
            int next = k + 1;
            while (nodes.count(prev)) {
                nodes.erase(prev);
                prev--;
                count++;
            }
            while (nodes.count(next)) {
                nodes.erase(next);
                next++;
                count++;
            }

            ans = max(count, ans);
        }
        return ans;
    }
};
