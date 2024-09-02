/*
m == rows in grid
n == cols in grid
runtime: O(m*n)
space: O(min(m*n))

To reason about the space complexity, imagine a 1x100 grid.

Another way to think about it is to visualize the BFS frontier as a diagonal "wave". If you draw
lines diagonally, you see that the longest these lines can be are min(m,n). See diagram.
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[r].size(); c++) {
                if (grid[r][c] == '1') {
                    destroyIslandBfs(grid, r, c);
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    void destroyIslandBfs(vector<vector<char>>& grid, int row, int col) {
        queue<pair<int, int>> q;

        q.push({row, col});
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r > 0 && grid[r - 1][c] == '1') {
                q.push({r - 1, c});
                grid[r - 1][c] = '0';
            }
            if (c > 0 && grid[r][c - 1] == '1') {
                q.push({r, c - 1});
                grid[r][c - 1] = '0';
            }
            if (r < grid.size() - 1 && grid[r + 1][c] == '1') {
                q.push({r + 1, c});
                grid[r + 1][c] = '0';
            }
            if (c < grid[r].size() - 1 && grid[r][c + 1] == '1') {
                q.push({r, c + 1});
                grid[r][c + 1] = '0';
            }
        }
    }
};

/*
m == rows in grid
n == cols in grid
runtime: O(m*n)
space: O(m*n)

To reason about the space complexity, imagine a 2x100 grid.
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[r].size(); c++) {
                if (grid[r][c] == '1') {
                    destroyIslandDfs(grid, r, c);
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    void destroyIslandDfs(vector<vector<char>>& grid, int row, int col) {
        stack<pair<int, int>> stk;

        stk.push({row, col});
        while (!stk.empty()) {
            auto [r, c] = stk.top();
            stk.pop();

            if (r > 0 && grid[r - 1][c] == '1') {
                stk.push({r - 1, c});
                grid[r - 1][c] = '0';
            }
            if (c > 0 && grid[r][c - 1] == '1') {
                stk.push({r, c - 1});
                grid[r][c - 1] = '0';
            }
            if (r < grid.size() - 1 && grid[r + 1][c] == '1') {
                stk.push({r + 1, c});
                grid[r + 1][c] = '0';
            }
            if (c < grid[r].size() - 1 && grid[r][c + 1] == '1') {
                stk.push({r, c + 1});
                grid[r][c + 1] = '0';
            }
        }
    }
};
