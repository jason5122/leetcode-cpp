#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
n == s.length()
runtime: O(2n)
space: O(n)
*/
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;

        int ans = 0;

        unordered_map<char, int> counts;
        int start = 0;
        for (int end = 0; end < s.length(); end++) {
            if (!counts.count(s[end]) && counts.size() == k) {
                while (counts.size() == k) {
                    counts[s[start]]--;
                    if (counts[s[start]] == 0) counts.erase(s[start]);
                    start++;
                }
            }
            counts[s[end]]++;
            ans = max(end - start + 1, ans);
        }
        return ans;
    }
};

/*
USED SOLUTION
*/
class Solution2 {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ans = 0;

        unordered_map<char, int> counts;
        int start = 0;
        for (int end = 0; end < s.length(); end++) {
            counts[s[end]]++;

            while (counts.size() > k) {
                counts[s[start]]--;
                if (counts[s[start]] == 0) counts.erase(s[start]);
                start++;
            }

            ans = max(end - start + 1, ans);
        }
        return ans;
    }
};

int main() {
    Solution2 solution;
    string s;
    int k;
    int ans;

    solution = Solution2();
    s = "eceba";
    k = 2;
    ans = solution.lengthOfLongestSubstringKDistinct(s, k);
    cout << ans << '\n';  // 3

    solution = Solution2();
    s = "aa";
    k = 1;
    ans = solution.lengthOfLongestSubstringKDistinct(s, k);
    cout << ans << '\n';  // 2
}
