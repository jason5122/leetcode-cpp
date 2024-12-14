/*
n == cost.size()
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> dp(size + 1, 0);

        for (int i = 2; i <= size; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[size];
    }
};

/*
n == cost.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = 0;
        int prev1 = 0;

        for (int i = 2; i <= cost.size(); i++) {
            int curr = min(prev1 + cost[i - 1], prev2 + cost[i - 2]);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
