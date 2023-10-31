/*
()[]{}

([)]

n == s.length()
runtime: O(n)
space: O(n)
*/
class Solution {
    bool is_opening_paren(char ch) {
        return ch == '(' || ch == '{' || ch == '[';
    }

    char get_matching_opening_paren(char ch) {
        switch (ch) {
        case ')':
            return '(';
        case '}':
            return '{';
        case ']':
            return '[';
        default:
            return 'x';  // invalid input
        }
    }

public:
    bool isValid(string s) {
        stack<char> stk;
        for (char ch : s) {
            if (is_opening_paren(ch)) {
                stk.push(ch);
            } else {
                if (stk.empty()) return false;
                if (get_matching_opening_paren(ch) != stk.top()) return false;

                stk.pop();
            }
        }
        return stk.empty();
    }
};
