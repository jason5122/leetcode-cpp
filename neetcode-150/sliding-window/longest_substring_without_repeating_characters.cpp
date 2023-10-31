/*
n == s.length()
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;

        int start = 0;
        unordered_set<char> used;
        for (int end = 0; end < s.length(); end++) {
            while (used.count(s[end])) {
                used.erase(s[start]);
                start++;
            }

            used.insert(s[end]);
            int len = used.size();
            ans = max(len, ans);
        }
        return ans;
    }
};
