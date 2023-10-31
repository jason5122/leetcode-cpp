/*
runtime: O(1)
space: O(1)
*/
class Solution {
    bool is_valid_sub_box(vector<vector<char>>& board, int row_offset, int col_offset) {
        unordered_set<char> seen;
        for (int r = row_offset; r < row_offset + 3; r++) {
            for (int c = col_offset; c < col_offset + 3; c++) {
                if (board[r][c] == '.') continue;

                if (seen.count(board[r][c])) return false;
                else seen.insert(board[r][c]);
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // rows
        for (int r = 0; r < 9; r++) {
            unordered_set<char> seen;
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;

                if (seen.count(board[r][c])) return false;
                else seen.insert(board[r][c]);
            }
        }

        // columns
        for (int c = 0; c < 9; c++) {
            unordered_set<char> seen;
            for (int r = 0; r < 9; r++) {
                if (board[r][c] == '.') continue;

                if (seen.count(board[r][c])) return false;
                else seen.insert(board[r][c]);
            }
        }

        // sub-boxes
        for (int row_offset = 0; row_offset < 9; row_offset += 3) {
            for (int col_offset = 0; col_offset < 9; col_offset += 3) {
                if (!is_valid_sub_box(board, row_offset, col_offset)) return false;
            }
        }
        return true;
    }
};
