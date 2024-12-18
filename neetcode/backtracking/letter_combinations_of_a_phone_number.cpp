/*
n == digits.length()
runtime: O(n*4^n)
space: O(n)
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (!digits.empty()) backtrack(digits, 0);
        return ans;
    }

private:
    vector<string> ans;
    string combo;

    unordered_map<char, vector<char>> mapping = {
        {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},      {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}}, {'6', {'m', 'n', 'o'}},      {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}},
    };

    void backtrack(string& digits, int i) {
        if (i == digits.length()) {
            ans.push_back(combo);
            return;
        }

        for (char ch : mapping[digits[i]]) {
            combo.push_back(ch);
            backtrack(digits, i + 1);
            combo.pop_back();
        }
    }
};
