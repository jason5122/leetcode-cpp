#include <iostream>
#include <vector>
using namespace std;

// m == matrix.size()
// n == matrix[0].size()
// runtime: O(m*n)
// space: O(1)
vector<int> spiral_order(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) return {};

    int rows = matrix.size();
    int cols = matrix[0].size();

    int r = 0;
    int c = 0;
    int padding_top = 0;
    int padding_bottom = 0;
    int padding_left = 0;
    int padding_right = 0;

    vector<int> result;
    bool is_stuck = true;
    while (true) {
        // right
        is_stuck = true;
        while (c < cols - padding_right) {
            result.push_back(matrix[r][c]);
            c++;
            is_stuck = false;
        }
        if (is_stuck) return result;
        padding_top++;
        c--;
        r++;

        // down
        is_stuck = true;
        while (r < rows - padding_bottom) {
            result.push_back(matrix[r][c]);
            r++;
            is_stuck = false;
        }
        if (is_stuck) return result;
        padding_right++;
        r--;
        c--;

        // left
        is_stuck = true;
        while (c >= 0 + padding_left) {
            result.push_back(matrix[r][c]);
            c--;
            is_stuck = false;
        }
        if (is_stuck) return result;
        padding_bottom++;
        c++;
        r--;

        // up
        is_stuck = true;
        while (r >= 0 + padding_top) {
            result.push_back(matrix[r][c]);
            r--;
            is_stuck = false;
        }
        if (is_stuck) return result;
        padding_left++;
        r++;
        c++;
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = spiral_order(matrix);  // [1,2,3,6,9,8,7,4,5]
    for (int n : result) cout << n << ' ';
    cout << '\n';

    matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    result = spiral_order(matrix);  // [1,2,3,4,8,12,11,10,9,5,6,7]
    for (int n : result) cout << n << ' ';
    cout << '\n';

    // USED SOLUTION
    matrix = {{6, 9, 7}};
    result = spiral_order(matrix);  // [6,9,7]
    for (int n : result) cout << n << ' ';
    cout << '\n';
}
