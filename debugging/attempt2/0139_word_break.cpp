#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
dp[j] = dp[i] && dict.count(s[i:j])

n == s.length()
runtime: O(n^2)
space: O(n)
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int n = s.length();
        vector<bool> dp(n + 1, false);

        // Base case.
        dp[0] = true;

        // Fill in sub-problems.
        for (int i = 0; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (dp[i] && dict.count(s.substr(i, j - i))) {
                    dp[j] = true;
                }
            }
        }

        return dp[n];
    }
};

/*
n == s.length()
runtime: O(n^2)
space: O(n)
*/
class Solution2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int n = s.length();

        queue<int> q;
        vector<bool> visited(n + 1);

        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n) return true;

            for (int j = i + 1; j <= n; j++) {
                if (!visited[j] && dict.count(s.substr(i, j - i))) {
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
        return false;
    }
};

/*
n == s.length()
runtime: O(n^2)
space: O(n)
*/
class Solution3 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        this->s = s;
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        memo = vector<optional<bool>>(n);
        return helper(0);
    }

private:
    int n;
    string s;
    unordered_set<string> dict;
    vector<optional<bool>> memo;

    bool helper(int i) {
        if (i == n) return true;
        if (memo[i]) return memo[i].value();

        bool res = false;
        for (int j = i + 1; j <= n; j++) {
            if (dict.count(s.substr(i, j - i))) {
                res |= helper(j);
            }
        }
        memo[i] = res;
        return res;
    }
};

int main() {
    Solution3 soln;
    string s;
    vector<string> wordDict;
    bool ans;

    soln = Solution3{};
    s = "leetcode";
    wordDict = {"leet", "code"};
    ans = soln.wordBreak(s, wordDict);
    cout << ans << '\n';  // true

    soln = Solution3{};
    s = "applepenapple";
    wordDict = {"apple", "pen"};
    ans = soln.wordBreak(s, wordDict);
    cout << ans << '\n';  // true

    soln = Solution3{};
    s = "catsandog";
    wordDict = {"cats", "dog", "sand", "and", "cat"};
    ans = soln.wordBreak(s, wordDict);
    cout << ans << '\n';  // false
}
