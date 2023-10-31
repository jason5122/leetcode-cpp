#include "debugging.h"
#include <unordered_set>
#include <vector>
using namespace std;

// runtime: O(1)
// space: O(1)
bool is_valid_sudoku(vector<vector<char>>& board) {
    // validate rows
    for (int r = 0; r < 9; r++) {
        unordered_set<int> used;
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') continue;

            if (used.count(board[r][c])) return false;
            else used.insert(board[r][c]);
        }
    }

    // validate cols
    for (int c = 0; c < 9; c++) {
        unordered_set<int> used;
        for (int r = 0; r < 9; r++) {
            if (board[r][c] == '.') continue;

            if (used.count(board[r][c])) return false;
            else used.insert(board[r][c]);
        }
    }

    // validate sub-boxes
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            unordered_set<int> used;
            for (int r = i; r < i + 3; r++) {
                for (int c = j; c < j + 3; c++) {
                    if (board[r][c] == '.') continue;

                    if (used.count(board[r][c])) return false;
                    else used.insert(board[r][c]);
                }
            }
        }
    }

    return true;
}

int main() {
    bool result;
    vector<vector<char>> board;

    board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    result = is_valid_sudoku(board);
    cout << result << '\n';  // true

    board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    result = is_valid_sudoku(board);
    cout << result << '\n';  // false
}
