/*
m == rows in grid
n == cols in grid
runtime: O(m*n)
space: O(min(m*n))
*/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[r].size(); c++) {
                int count = sizeOfIslandBfs(grid, r, c);
                ans = max(count, ans);
            }
        }
        return ans;
    }

private:
    int sizeOfIslandBfs(vector<vector<int>>& grid, int row, int col) {
        queue<pair<int, int>> q;

        if (grid[row][col] == 1) {
            q.push({row, col});
            grid[row][col] = 0;
        }

        int count = 0;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            count++;

            if (r > 0 && grid[r - 1][c] == 1) {
                q.push({r - 1, c});
                grid[r - 1][c] = 0;
            }
            if (c > 0 && grid[r][c - 1] == 1) {
                q.push({r, c - 1});
                grid[r][c - 1] = 0;
            }
            if (r < grid.size() - 1 && grid[r + 1][c] == 1) {
                q.push({r + 1, c});
                grid[r + 1][c] = 0;
            }
            if (c < grid[r].size() - 1 && grid[r][c + 1] == 1) {
                q.push({r, c + 1});
                grid[r][c + 1] = 0;
            }
        }
        return count;
    }
};
