/*
n == s.length()
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> count;
        for (char ch : s) {
            count[ch]++;
        }

        unordered_set<char> seen;
        stack<char> stk;
        for (char ch : s) {
            if (!seen.count(ch)) {
                while (!stk.empty() && count[stk.top()] > 0 && ch < stk.top()) {
                    seen.erase(stk.top());
                    stk.pop();
                }
                seen.insert(ch);
                stk.push(ch);
            }

            count[ch]--;
        }

        string ans;
        ans.reserve(stk.size());
        while (!stk.empty()) {
            ans.insert(0, 1, stk.top());
            stk.pop();
        }
        return ans;
    }
};
