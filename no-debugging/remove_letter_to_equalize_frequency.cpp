/*
USED HINTS
n == word.length()
runtime: O(n+26*26)
space: O(26)
*/
class Solution {
public:
    bool equalFrequency(string word) {
        int freqs[26] = {0};
        for (char ch : word) freqs[ch - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (freqs[i] == 0) continue;

            freqs[i]--;

            bool possible = true;
            int prev = -1;
            for (int j = 0; j < 26; j++) {
                if (freqs[j] == 0) continue;

                if (prev == -1) {
                    prev = freqs[j];
                } else if (freqs[j] != prev) {
                    possible = false;
                }
            }
            if (possible) return true;

            freqs[i]++;
        }
        return false;
    }
};
