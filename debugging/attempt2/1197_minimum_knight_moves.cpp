#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
m == 600
n == 600
runtime: O(m*n)
space: O(m*n)?
*/
class Solution {
public:
    int minKnightMoves(int target_x, int target_y) {
        pair<int, int> kKnightMoves[8]{
            {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
        };

        int m = 600;
        int n = 600;
        vector<vector<bool>> visited(m + 1, vector<bool>(n + 1, false));

        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                if (x == target_x && y == target_y) {
                    return depth;
                }

                for (auto& [dx, dy] : kKnightMoves) {
                    int new_x = x + dx;
                    int new_y = y + dy;
                    if (!hasVisited(new_x, new_y, visited)) {
                        q.push({new_x, new_y});
                        markVisited(new_x, new_y, visited);
                    }
                }
            }
            depth++;
        }
        return depth;
    }

private:
    bool hasVisited(int x, int y, vector<vector<bool>>& visited) {
        int i = x + 300;
        int j = y + 300;
        if (i < 0 || j < 0) return true;      // Invalid coordinate; skip.
        if (i > 600 || j > 600) return true;  // Invalid coordinate; skip.
        return visited[i][j];
    }

    void markVisited(int x, int y, vector<vector<bool>>& visited) {
        int i = x + 300;
        int j = y + 300;
        visited[i][j] = true;
    }
};

int main() {
    Solution soln;
    int x, y;
    int ans;

    soln = Solution{};
    x = 2, y = 1;
    ans = soln.minKnightMoves(x, y);
    cout << ans << '\n';  // 1

    soln = Solution{};
    x = 5, y = 5;
    ans = soln.minKnightMoves(x, y);
    cout << ans << '\n';  // 4
}
