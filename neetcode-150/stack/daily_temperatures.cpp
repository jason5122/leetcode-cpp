/*
[30, 20, 40] -> [2, 1, 0]

n == temperatures.size()
runtime: O(2n)
space: O(n)
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);

        stack<int> stk;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                ans[stk.top()] = i - stk.top();
                stk.pop();
            }

            stk.push(i);
        }

        // while (!stk.empty()) {
        //     ans[stk.top()] = 0;
        //     stk.pop();
        // }

        return ans;
    }
};
