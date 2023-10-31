#include <iostream>
#include <vector>
using namespace std;

// m == matrix.size()
// n == matrix[0].size()
// runtime: O(m*n)
// space: O(m+n)
void set_zeroes(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) return;

    vector<bool> zero_rows(matrix.size(), false);
    vector<bool> zero_cols(matrix[0].size(), false);

    for (int r = 0; r < matrix.size(); r++) {
        for (int c = 0; c < matrix[r].size(); c++) {
            if (matrix[r][c] == 0) {
                zero_rows[r] = true;
                zero_cols[c] = true;
            }
        }
    }

    for (int r = 0; r < matrix.size(); r++) {
        for (int c = 0; c < matrix[r].size(); c++) {
            if (zero_rows[r] || zero_cols[c]) {
                matrix[r][c] = 0;
            }
        }
    }
}

void print_matrix(vector<vector<int>>& matrix) {
    for (vector<int> row : matrix) {
        for (int n : row) {
            cout << n << ' ';
        }
        cout << '\n';
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    set_zeroes(matrix);
    print_matrix(matrix);

    cout << '\n';

    matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    set_zeroes(matrix);
    print_matrix(matrix);
}
