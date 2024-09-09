/*
n == prices.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int buy = prices[0];
        for (int p : prices) {
            if (p > buy) {
                ans += p - buy;
                buy = p;
            } else {
                buy = p;
            }
        }
        return ans;
    }
};
