/*
n == nums.size()
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_set(nums.begin(), nums.end());

        int max_streak = 0;
        for (int n : nums) {
            if (!hash_set.count(n - 1)) {
                int streak = 0;
                int curr = n;
                while (hash_set.count(curr)) {
                    streak++;
                    curr++;
                    max_streak = max(streak, max_streak);
                }
            }
        }
        return max_streak;
    }
};
