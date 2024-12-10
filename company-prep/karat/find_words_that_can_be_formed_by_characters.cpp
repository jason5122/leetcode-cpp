/*
n == words.size()
k == chars.length()
runtime: O(n*k)
space: O(k)
*/
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        for (string& word : words) {
            if (can_be_formed(word, chars)) {
                ans += word.length();
            }
        }
        return ans;
    }

private:
    bool can_be_formed(string& word, string& chars) {
        unordered_map<int, int> count;
        for (char ch : chars) count[ch]++;

        for (char ch : word) {
            if (count[ch] == 0) return false;
            else count[ch]--;
        }
        return true;
    }
};
