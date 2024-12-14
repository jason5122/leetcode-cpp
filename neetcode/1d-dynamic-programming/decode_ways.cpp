/*
dp[i] = dp[i - 1] + dp[i - 2] (only if mappings are valid for each)

n == s.length()
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int numDecodings(string s) {
        unordered_set<string> mapping;
        for (int k = 1; k <= 26; k++) {
            mapping.insert(to_string(k));
        }

        int n = s.length();
        vector<int> dp(n + 1, 0);

        // Base case.
        dp[0] = 1;
        dp[1] = mapping.count(s.substr(0, 1));

        // Fill in sub-problems.
        for (int i = 2; i <= n; i++) {
            if (mapping.count(s.substr(i - 1, 1))) {
                dp[i] += dp[i - 1];
            }
            if (mapping.count(s.substr(i - 2, 2))) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};
