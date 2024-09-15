/*
m == obstacleGrid.size()
n == obstacleGrid[0].size()
runtime: O(m*n)
space: O(m*n)
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base case.
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0]) break;
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j]) break;
            dp[0][j] = 1;
        }

        // Fill in sub-problems.
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j]) continue;

                if (!obstacleGrid[i - 1][j]) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (!obstacleGrid[i][j - 1]) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
