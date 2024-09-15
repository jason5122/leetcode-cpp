#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    int m;
    int n;
    vector<vector<bool>> visited;

    bool backtrack(vector<vector<char>>& board, string& word, int r, int c,
                   int i) {
        if (i == word.length()) return true;
        if (board[r][c] != word[i]) return false;
        if (i == word.length() - 1) return true;

        visited[r][c] = true;
        if (r - 1 >= 0 && !visited[r - 1][c]) {
            if (backtrack(board, word, r - 1, c, i + 1)) return true;
        }
        if (r + 1 < m && !visited[r + 1][c]) {
            if (backtrack(board, word, r + 1, c, i + 1)) return true;
        }
        if (c - 1 >= 0 && !visited[r][c - 1]) {
            if (backtrack(board, word, r, c - 1, i + 1)) return true;
        }
        if (c + 1 < n && !visited[r][c + 1]) {
            if (backtrack(board, word, r, c + 1, i + 1)) return true;
        }
        visited[r][c] = false;
        return false;
    }

public:
    // USED SOLUTION
    // m == board.size()
    // n == board[0].size()
    // l == word.length()
    // runtime: O(m*n*3^l)
    // space: O(m*n+l)
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (backtrack(board, word, r, c, 0)) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    bool result = s.exist(board, word);  // true
    cout << result << '\n';

    word = "SEE";
    result = s.exist(board, word);  // true
    cout << result << '\n';

    word = "ABCB";
    result = s.exist(board, word);  // false
    cout << result << '\n';

    // USED SOLUTION
    board = {{'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'},
             {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'},
             {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}};
    word = "AAAAAAAAAAAABAA";
    result = s.exist(board, word);  // false
    cout << result << '\n';

    // USED SOLUTION
    board = {{'a'}};
    word = "a";
    result = s.exist(board, word);  // true
    cout << result << '\n';
}
