/*
USED TEST CASE
s = "yfttttfbbbbnnnnffbgffffgbbbbgssssgthyyyy", k = 4

USED HINTS
n == s.length()
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> stk;
        stack<int> freqs;

        for (char ch : s) {
            if (!freqs.empty() && ch == stk.top()) {
                int old_freq = freqs.top();
                freqs.pop();
                freqs.push(old_freq + 1);
            } else {
                freqs.push(1);
            }
            stk.push(ch);

            if (freqs.top() == k) {
                for (int i = 0; i < k; i++) stk.pop();
                freqs.pop();
            }
        }

        string ans;
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
