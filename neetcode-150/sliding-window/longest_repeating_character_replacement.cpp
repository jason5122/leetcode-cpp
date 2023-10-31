/*
USED SOLUTION
n == s.length()
runtime: O(2n)
space: O(n)
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;

        unordered_map<char, int> counts;
        int max_count = 0;
        int start = 0;
        for (int end = 0; end < s.length(); end++) {
            counts[s[end]]++;

            max_count = max(counts[s[end]], max_count);
            if (end - start + 1 - max_count > k) {
                counts[s[start]]--;
                start++;
            }

            ans = max(end - start + 1, ans);
        }
        return ans;
    }
};
