/*
abc
ababab

abac

n == s2.length()
k == s1.length()
runtime: O(2n)
space: O(k)
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> counts;
        for (char ch : s1) counts[ch]++;

        int start = 0;
        for (int end = 0; end < s2.length(); end++) {
            counts[s2[end]]--;

            while (counts[s2[end]] < 0) {
                counts[s2[start]]++;
                start++;
            }

            if (counts[s2[end]] == 0) counts.erase(s2[end]);
            if (counts.empty()) return true;
        }
        return false;
    }
};
