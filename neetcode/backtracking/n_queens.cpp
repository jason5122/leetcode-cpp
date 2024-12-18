/*
runtime: O(n!)
space: O(n)
*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        backtrack(0);
        return ans;
    }

private:
    int n;
    vector<vector<string>> ans;
    vector<string> comb;
    vector<int> cols;

    void backtrack(int row) {
        if (row == n) {
            ans.push_back(comb);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (is_valid(cols, row, c)) {
                comb.push_back(create_string(c));
                cols.push_back(c);
                backtrack(row + 1);
                comb.pop_back();
                cols.pop_back();
            }
        }
    }

    bool is_valid(vector<int>& cols, int row, int col) {
        for (int r = 0; r < cols.size(); r++) {
            // Same column.
            if (cols[r] == col) return false;
            // Same diagonal.
            if (abs(row - r) == abs(col - cols[r])) return false;
        }
        return true;
    }

    string create_string(int c) {
        string s;
        for (int i = 0; i < n; i++) {
            s += i == c ? 'Q' : '.';
        }
        return s;
    }
};
