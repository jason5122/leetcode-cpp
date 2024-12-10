/*
USED TEST CASE

board =
[["A","B","C","E"],
 ["S","F","E","S"],
 ["A","D","E","E"]]

word = "ABCESEEEFS"

n == # of cells
k == word.length()
runtime: O(n*3^k)
space: O(k)
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[r].size(); c++) {
                unordered_map<int, unordered_map<int, bool>> visited;
                visited[r][c] = true;

                if (board[r][c] == word[0] && dfs(r, c, board, word, 1, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(int r, int c, vector<vector<char>>& board, string& word, int i,
             unordered_map<int, unordered_map<int, bool>>& visited) {
        if (i == word.length()) return true;

        int rows = board.size();
        int cols = board[r].size();

        bool ans = false;
        if (r < rows - 1 && !visited[r + 1][c] && board[r + 1][c] == word[i]) {
            visited[r + 1][c] = true;
            ans |= dfs(r + 1, c, board, word, i + 1, visited);
            visited[r + 1][c] = false;
        }
        if (r > 0 && !visited[r - 1][c] && board[r - 1][c] == word[i]) {
            visited[r - 1][c] = true;
            ans |= dfs(r - 1, c, board, word, i + 1, visited);
            visited[r - 1][c] = false;
        }
        if (c < cols - 1 && !visited[r][c + 1] && board[r][c + 1] == word[i]) {
            visited[r][c + 1] = true;
            ans |= dfs(r, c + 1, board, word, i + 1, visited);
            visited[r][c + 1] = false;
        }
        if (c > 0 && !visited[r][c - 1] && board[r][c - 1] == word[i]) {
            visited[r][c - 1] = true;
            ans |= dfs(r, c - 1, board, word, i + 1, visited);
            visited[r][c - 1] = false;
        }
        return ans;
    }
};

/*
n == # of cells
k == word.length()
runtime: O(n*3^k)
space: O(k)
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->m = board.size();
        this->n = board[0].size();

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[r].size(); c++) {
                unordered_map<int, unordered_map<int, bool>> visited;
                visited[r][c] = true;

                if (board[r][c] == word[0] && dfs(r, c, board, word, 1, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    int m, n;

    bool dfs(int row, int col, vector<vector<char>>& board, string& word, int i,
             unordered_map<int, unordered_map<int, bool>>& visited) {
        if (i == word.length()) return true;

        constexpr pair<int, int> diffs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        bool ans = false;
        for (auto [dr, dc] : diffs) {
            int r = row + dr;
            int c = col + dc;
            if (is_valid(r, c) && !visited[r][c] && board[r][c] == word[i]) {
                visited[r][c] = true;
                ans |= dfs(r, c, board, word, i + 1, visited);
                visited[r][c] = false;
            }
        }
        return ans;
    }

    bool is_valid(int r, int c) {
        return (0 <= r && r < m) && (0 <= c && c < n);
    }
};
