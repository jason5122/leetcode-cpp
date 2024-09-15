#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
n == s.length()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    bool isPalindrome(string s) {
        stringstream ss;
        for (char ch : s) {
            ch = tolower(ch);
            if (isalnum(ch)) ss << ch;
        }
        s = ss.str();

        int len = s.length();
        for (int i = 0; i < len / 2; i++) {
            if (s[i] != s[len - 1 - i]) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    string s;
    bool result;

    solution = Solution();
    s = "A man, a plan, a canal: Panama";
    result = solution.isPalindrome(s);
    cout << result << '\n';  // true

    solution = Solution();
    s = "race a car";
    result = solution.isPalindrome(s);
    cout << result << '\n';  // false

    solution = Solution();
    s = " ";
    result = solution.isPalindrome(s);
    cout << result << '\n';  // true
}
