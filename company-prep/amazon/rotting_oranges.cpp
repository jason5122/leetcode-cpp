/*
m == grid.size()
n == grid[0].size()
runtime: O(m+n)
space: O(m*n)
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        // TODO: Use a different data structure to store visited.
        set<pair<int, int>> visited;

        int m = grid.size();
        int n = grid[0].size();

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                }
            }
        }

        int depth = 0;
        while (!q.empty()) {
            bool has_new = false;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                if (!visited.count({r - 1, c}) && r > 0 && grid[r - 1][c] == 1) {
                    q.push({r - 1, c});
                    visited.insert({r - 1, c});
                    has_new = true;
                }
                if (!visited.count({r + 1, c}) && r < m - 1 && grid[r + 1][c] == 1) {
                    q.push({r + 1, c});
                    visited.insert({r + 1, c});
                    has_new = true;
                }
                if (!visited.count({r, c - 1}) && c > 0 && grid[r][c - 1] == 1) {
                    q.push({r, c - 1});
                    visited.insert({r, c - 1});
                    has_new = true;
                }
                if (!visited.count({r, c + 1}) && c < n - 1 && grid[r][c + 1] == 1) {
                    q.push({r, c + 1});
                    visited.insert({r, c + 1});
                    has_new = true;
                }
            }
            if (has_new) {
                depth++;
            }
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1 && !visited.count({r, c})) {
                    return -1;
                }
            }
        }
        return depth;
    }
};
