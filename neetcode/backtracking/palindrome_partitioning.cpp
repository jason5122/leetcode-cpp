/*
n == s.length()
runtime: O(n*2^n)
space: O(n)

Copying the subsets over takes O(n) time.
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return ans;
    }

private:
    vector<vector<string>> ans;
    vector<string> subset;

    void backtrack(string& s, int start) {
        if (start == s.length()) {
            ans.push_back(subset);
            return;
        }

        for (int i = start; i < s.length(); i++) {
            string substr = s.substr(start, i - start + 1);
            if (is_palindrome(substr)) {
                subset.push_back(substr);
                backtrack(s, i + 1);
                subset.pop_back();
            }
        }
    }

    bool is_palindrome(string& s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i]) return false;
        }
        return true;
    }
};
