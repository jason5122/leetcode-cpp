/*
()
(()), ()()
((())), (()()), (())(), ()(()), ()()()

runtime: O(2^n)?
space: O(2n)
*/
class Solution {
    vector<string> ans;
    string curr;

    void backtrack(int open, int close) {
        if (close < open) return;

        if (open == 0 && close == 0) {
            ans.push_back(curr);
            return;
        }

        if (open > 0) {
            curr += '(';
            backtrack(open - 1, close);
            curr.pop_back();
        }

        if (close > 0) {
            curr += ')';
            backtrack(open, close - 1);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        backtrack(n, n);
        return ans;
    }
};
