/*
m == ransomNote.length()
n == magazine.length()
runtime: O(m+n)
space: O(n)
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freqs;
        for (char ch : magazine) freqs[ch]++;

        for (char ch : ransomNote) {
            if (freqs[ch] == 0) return false;
            else freqs[ch]--;
        }
        return true;
    }
};
