/*
NOT DYNAMIC PROGRAMMING
n == s.length()
runtime: O(n^2)
space: O(1)
*/
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            ans += expand(s, i, i);      // Odd palindromes.
            ans += expand(s, i, i + 1);  // Even palindromes.
        }
        return ans;
    }

private:
    int expand(string& s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < s.length()) {
            if (s[l] != s[r]) break;

            count++;
            l--;
            r++;
        }
        return count;
    }
};

/*
dp[i][j] = dp[i+1][j-1] && s[i] == s[j]

n == s.length()
runtime: O(n^2)
space: O(n^2)
*/
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int count = 0;

        // Base case.
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            count++;
        }
        for (int i = 0; i < n - 1; i++) {
            int j = i + 1;
            if (s[i] == s[j]) {
                dp[i][j] = true;
                count++;
            }
        }

        // Fill out sub-problems.
        for (int k = 2; k < n; k++) {
            for (int i = 0; i < n - k; i++) {
                int j = i + k;
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    count++;
                }
            }
        }

        return count;
    }
};
