/*
dp[j] = dp[i] && wordDict contains s[i:j]

n == s.length()
runtime: O(n^2)
space: O(n)
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        unordered_set<string> dict{wordDict.begin(), wordDict.end()};

        // Base case.
        dp[0] = true;

        // Fill in sub-problems.
        for (int i = 0; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                string word = s.substr(i, j - i);
                if (dp[i] && dict.count(word)) {
                    dp[j] = true;
                }
            }
        }

        return dp[n];
    }
};
