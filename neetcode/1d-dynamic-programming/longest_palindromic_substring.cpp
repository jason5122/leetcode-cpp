/*
NOT DYNAMIC PROGRAMMING
n == s.length()
runtime: O(n^2)
space: O(1)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            string odd = expand(s, i, i);
            string even = expand(s, i, i + 1);

            if (odd.length() > ans.length()) {
                ans = odd;
            }
            if (even.length() > ans.length()) {
                ans = even;
            }
        }
        return ans;
    }

private:
    string expand(string& s, int l, int r) {
        while (l >= 0 && r < s.length()) {
            if (s[l] != s[r]) break;

            l--;
            r++;
        }

        l++;
        r--;
        return s.substr(l, r - l + 1);
    }
};

/*
USED SOLUTION

i = substring start index
j = substring end index
dp[i][j] = dp[i+1][j-1] && s[i] == s[j]

n == s.length()
runtime: O(n^2)
space: O(n^2)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        array<int, 2> ans = {0, 0};

        // Base case.
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            int j = i + 1;
            if (s[i] == s[j]) {
                dp[i][j] = true;
                ans = {i, j};
            }
        }

        // Fill out sub-problems.
        for (int k = 2; k < n; k++) {
            for (int i = 0; i < n - k; i++) {
                int j = i + k;
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    ans = {i, j};
                }
            }
        }

        auto [i, j] = ans;
        return s.substr(i, j - i + 1);
    }
};
