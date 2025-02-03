class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freqs;

        int start = 0;
        int ans = 0;
        for (int end = 0; end < s.length(); end++) {
            freqs[s[end]]++;

            while (freqs[s[end]] > 1) {
                freqs[s[start]]--;
                start++;
            }

            int len = end - start + 1;
            ans = max(len, ans);
        }
        return ans;
    }
};
