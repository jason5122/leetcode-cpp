/*
n == s.length()
runtime: O(n^2)
space: O(n)
*/
constexpr auto operator*(std::string_view sv, int times) {
    string result;
    for (int i = 0; i < times; i++) {
        result += sv;
    }
    return result;
}
constexpr auto operator*(int times, std::string_view sv) {
    return sv * times;
}

class Solution {
public:
    string decodeString(string s) {
        int n = s.length();

        stack<string> stk;
        stack<int> multiplier;

        stk.push("");
        multiplier.push(1);
        int i = 0;
        while (i < n) {
            if (isalpha(s[i])) {
                stk.top() += s[i];
            } else if (isdigit(s[i])) {
                string k_str;
                while (isdigit(s[i])) k_str += s[i++];
                int k = stoi(k_str);

                stk.push("");
                multiplier.push(k);
            } else if (s[i] == ']') {
                string nested = stk.top();  // A string within a set of [].
                int k = multiplier.top();
                stk.pop();
                multiplier.pop();

                stk.top() += nested * k;
            }
            i++;
        }
        return stk.top();
    }
};
