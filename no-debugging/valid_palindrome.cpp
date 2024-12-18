/*
n == s.length()
runtime: O(n)
space: O(n)

Filtering the string takes O(n) time.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (char ch : s) {
            if (isalnum(ch)) str += tolower(ch);
        }

        int n = str.length();
        for (int i = 0; i < n / 2; i++) {
            if (str[i] != str[n - 1 - i]) return false;
        }
        return true;
    }
};
