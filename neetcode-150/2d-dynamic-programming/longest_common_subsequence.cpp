/*
USED SOLUTION
m == text1.length()
n == text2.length()
runtime: O(2^max(m,n))
space: O(max(m,n))
*/
class Solution {
    int lcs(string& s1, string& s2, int m, int n) {
        if (m == -1 || n == -1) return 0;

        if (s1[m] == s2[n]) {
            return 1 + lcs(s1, s2, m - 1, n - 1);
        } else {
            return max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
        }
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        return lcs(text1, text2, m - 1, n - 1);
    }
};

/*
m == text1.length()
n == text2.length()
runtime: O(m*n)
space: O(m*n)
*/
class Solution {
    unordered_map<int, unordered_map<int, int>> cache;

    int lcs_cached(string& s1, string& s2, int m, int n) {
        if (cache.count(m) && cache[m].count(n)) {
            return cache[m][n];
        } else {
            int ans = lcs(s1, s2, m, n);
            cache[m][n] = ans;
            return ans;
        }
    }

    int lcs(string& s1, string& s2, int m, int n) {
        if (m == -1 || n == -1) return 0;

        if (s1[m] == s2[n]) {
            return 1 + lcs_cached(s1, s2, m - 1, n - 1);
        } else {
            return max(lcs_cached(s1, s2, m - 1, n), lcs_cached(s1, s2, m, n - 1));
        }
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        return lcs(text1, text2, m - 1, n - 1);
    }
};

/*
USED SOLUTION
m == text1.length()
n == text2.length()
runtime: O(m*n)
space: O(m*n)
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};
