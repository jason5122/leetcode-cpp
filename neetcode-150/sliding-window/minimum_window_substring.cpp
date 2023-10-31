/*
abc
axxxbcxca

abbbcca

DEBUGGED
n == s.length()
k == t.length()
runtime: O(n+k*n)
space: O(k)
*/
class Solution {
    bool is_valid(unordered_map<char, int>& counts) {
        for (const auto& [ch, count] : counts) {
            if (count > 0) return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        int min_start = -1;
        int min_len = INT_MAX;

        unordered_map<char, int> counts;
        for (char ch : t) counts[ch]++;

        int start = 0;
        for (int end = 0; end < s.length(); end++) {
            if (!counts.count(s[end])) continue;

            counts[s[end]]--;

            while (is_valid(counts)) {
                int len = end - start + 1;
                if (len < min_len) {
                    min_start = start;
                    min_len = len;
                }

                if (counts.count(s[start])) counts[s[start]]++;
                start++;
            }
        }
        return min_start == -1 ? "" : s.substr(min_start, min_len);
    }
};
