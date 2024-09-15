#include "debugging.h"
#include "leetcode.h"
using namespace std;

class Solution {
public:
    int minKnightMoves(int x, int y) {
        int rows = 300;
        int cols = 300;

        if (x < 0) x *= -1;
        if (y < 0) y *= -1;

        vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
        dp[0][0] = 0;
        dp[1][2] = 1;
        dp[2][1] = 1;
        dp[2][0] = 2;
        dp[0][2] = 2;
        dp[1][1] = 2;
        dp[1][0] = 3;
        dp[0][1] = 3;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // ordered clockwise
                int m1 = r + 2 < rows && c + 1 < cols ? dp[r + 2][c + 1] : INT_MAX;
                int m2 = r + 1 < rows && c + 2 < cols ? dp[r + 1][c + 2] : INT_MAX;
                int m3 = r - 1 >= 0 && c + 2 < cols ? dp[r - 1][c + 2] : INT_MAX;
                int m4 = r - 2 >= 0 && c + 1 < cols ? dp[r - 2][c + 1] : INT_MAX;
                int m5 = r - 2 >= 0 && c - 1 >= 0 ? dp[r - 2][c - 1] : INT_MAX;
                int m6 = r - 1 >= 0 && c - 2 >= 0 ? dp[r - 1][c - 2] : INT_MAX;
                int m7 = r + 1 < rows && c - 2 >= 0 ? dp[r + 1][c - 2] : INT_MAX;
                int m8 = r + 2 < rows && c - 1 >= 0 ? dp[r + 2][c - 1] : INT_MAX;

                if (m1 != INT_MAX) m1++;
                if (m2 != INT_MAX) m2++;
                if (m3 != INT_MAX) m3++;
                if (m4 != INT_MAX) m4++;
                if (m5 != INT_MAX) m5++;
                if (m6 != INT_MAX) m6++;
                if (m7 != INT_MAX) m7++;
                if (m8 != INT_MAX) m8++;

                dp[r][c] = min({dp[r][c], m1, m2, m3, m4, m5, m6, m7, m8});
            }
        }

        return dp[x][y];
    }
};

// USED SOLUTION
// WARNING: slow because this uses std::vector instead of std::pair
class Solution2 {
    // the offsets in the eight directions
    vector<vector<int>> offsets = {{2, 1},   {1, 2},   {-1, 2}, {-2, 1},
                                   {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

public:
    int minKnightMoves(int x, int y) {
        if (x < 0) x *= -1;
        if (y < 0) y *= -1;

        queue<vector<int>> q;
        bool visited[605][605];
        memset(visited, false, sizeof(visited));

        q.push({0, 0});
        visited[302][302] = true;

        int depth = 0;
        while (!q.empty()) {
            // process current depth
            int size = q.size();
            while (size--) {
                vector<int> curr = q.front();
                q.pop();

                if (curr[0] == x && curr[1] == y) return depth;

                for (const auto& offset : offsets) {
                    vector<int> next = {curr[0] + offset[0], curr[1] + offset[1]};

                    if (!visited[next[0] + 302][next[1] + 302]) {
                        visited[next[0] + 302][next[1] + 302] = true;
                        q.push(next);
                    }
                }
            }
            depth++;
        }
        return -1;
    }
};

// USED SOLUTION
class Solution3 {
    // the offsets in the eight directions
    vector<pair<int, int>> offsets = {{2, 1},   {1, 2},   {-1, 2}, {-2, 1},
                                      {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

public:
    int minKnightMoves(int x, int y) {
        queue<pair<int, int>> q;
        bool visited[605][605];
        memset(visited, false, sizeof(visited));

        q.push({0, 0});
        visited[302][302] = true;

        int depth = 0;
        while (!q.empty()) {
            // process current depth
            int size = q.size();
            while (size--) {
                pair<int, int> curr = q.front();
                q.pop();

                if (curr.first == x && curr.second == y) return depth;

                for (const auto& offset : offsets) {
                    pair<int, int> next = {curr.first + offset.first, curr.second + offset.second};

                    if (!visited[next.first + 302][next.second + 302]) {
                        visited[next.first + 302][next.second + 302] = true;
                        q.push(next);
                    }
                }
            }
            depth++;
        }
        return depth;
    }
};

int main() {
    Solution3 solution;
    int result;
    int x, y;

    solution = Solution3();
    x = 2;
    y = 1;
    result = solution.minKnightMoves(x, y);
    cout << result << '\n';  // 1

    solution = Solution3();
    x = 5;
    y = 5;
    result = solution.minKnightMoves(x, y);
    cout << result << '\n';  // 4

    // USED SOLUTION
    solution = Solution3();
    x = 0;
    y = 1;
    result = solution.minKnightMoves(x, y);
    cout << result << '\n';  // 3

    // USED SOLUTION
    solution = Solution3();
    x = 1;
    y = 1;
    result = solution.minKnightMoves(x, y);
    cout << result << '\n';  // 2

    // USED SOLUTION
    solution = Solution3();
    x = 300;
    y = 0;
    result = solution.minKnightMoves(x, y);
    cout << result << '\n';  // 150
}
