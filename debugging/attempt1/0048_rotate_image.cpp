#include <iostream>
#include <vector>
using namespace std;

void rotate_90(vector<vector<int>>& matrix, int r, int c) {
    int n = matrix.size();
    int temp = matrix[r][c];
    matrix[c][n - 1 - r] = temp;
}

// USED SOLUTION
// n == matrix.size()
// runtime: O(n)
// space: O(1)
void rotate(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) return;

    int n = matrix.size();
    for (int r = 0; r <= (n + 1) / 2; r++) {
        for (int c = 0; c < n / 2; c++) {
            int temp = matrix[n - 1 - c][r];
            rotate_90(matrix, n - 1 - r, n - 1 - c);
            rotate_90(matrix, c, n - 1 - r);
            rotate_90(matrix, r, c);
            matrix[r][c] = temp;
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
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(matrix);
    print_matrix(matrix);  // [[7,4,1],[8,5,2],[9,6,3]]

    cout << '\n';

    matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    rotate(matrix);
    print_matrix(matrix);  // [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
}
