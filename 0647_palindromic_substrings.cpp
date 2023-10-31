#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
abc

a
b, ab
c, bc


aaa

a      -> 1
a, aa  -> 2 + 1
a, aa  -> 1 + 1

n == s.length()
runtime: O(n^2)
space: O(1)
*/
class Solution {
    int helper(string& s, int l, int r) {
        int ans = 0;

        int n = s.length();
        while (l >= 0 && r < n) {
            if (s[l] == s[r]) {
                ans++;
                l--;
                r++;
            } else {
                break;
            }
        }
        return ans;
    }

public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            ans += helper(s, i, i);
            if (i > 0) ans += helper(s, i - 1, i);
        }
        return ans;
    }
};

/*
USED SOLUTION
n == s.length()
runtime: O(n^2)
space: O(n^2)
*/
class Solution2 {
public:
    int countSubstrings(string s) {
        int n = s.length();

        int ans = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {  // 1-length palindromes
            dp[i][i] = true;
            ans++;
        }
        for (int i = 0; i < n - 1; i++) {  // 2-length palindromes
            dp[i][i + 1] = s[i] == s[i + 1];
            if (dp[i][i + 1]) ans++;
        }

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (dp[i + 1][j - 1] && s[i] == s[j]) dp[i][j] = true;

                if (dp[i][j]) ans++;
            }
        }

        // ALTERNATE
        // for (int i = n - 1; i >= 0; i--) {
        //     for (int j = i; j < n; j++) {
        //         int len = j - i + 1;
        //         if (len < 3) continue;

        //         if (dp[i + 1][j - 1] && s[i] == s[j]) dp[i][j] = true;

        //         if (dp[i][j]) ans++;
        //     }
        // }

        return ans;
    }
};

int main() {
    cout << boolalpha;

    Solution2 solution;
    string s;
    int ans;

    solution = Solution2();
    s = "abc";
    ans = solution.countSubstrings(s);
    cout << ans << '\n';  // 3

    solution = Solution2();
    s = "aaa";
    ans = solution.countSubstrings(s);
    cout << ans << '\n';  // 6

    // USED SOLUTION
    solution = Solution2();
    s = "aaaaa";
    ans = solution.countSubstrings(s);
    cout << ans << '\n';  // 15

    // CUSTOM
    solution = Solution2();
    s = "aaaaaa";
    ans = solution.countSubstrings(s);
    cout << ans << '\n';  // 21

    // CUSTOM
    solution = Solution2();
    s = "aaaaaaa";
    ans = solution.countSubstrings(s);
    cout << ans << '\n';  // 28
}
