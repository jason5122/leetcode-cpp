/*
m == s.length()
n == t.length()
runtime: O(m+n)
space: O(m)
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> counts;
        for (char ch : s) {
            counts[ch]++;
        }

        for (char ch : t) {
            if (!counts.count(ch)) return false;

            counts[ch]--;
            if (counts[ch] == 0) counts.erase(ch);
        }
        return true;
    }
};
