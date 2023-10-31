/*
n == tokens.size()
runtime: O(2n)
space: O(n)
*/
class Solution {
    bool is_operator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int apply_op(char op, int n1, int n2) {
        switch (op) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            return static_cast<int>(n1 / n2);
        default:
            return -1;  // invalid op
        }
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (const auto& token : tokens) {
            if (is_operator(token)) {
                char op = token[0];

                int n2 = stk.top();
                stk.pop();
                int n1 = stk.top();
                stk.pop();

                int result = apply_op(op, n1, n2);
                stk.push(result);
            } else {
                int n = stoi(token);
                stk.push(n);
            }
        }
        return stk.top();
    }
};
