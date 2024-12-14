/*
n == prices.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;

        int start = 0;
        for (int end = 1; end < prices.size(); end++) {
            while (start < end && prices[start] > prices[end]) {
                start++;
            }
            ans = max(prices[end] - prices[start], ans);
        }
        return ans;
    }
};
