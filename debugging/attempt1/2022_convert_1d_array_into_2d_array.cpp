#include <iostream>
#include <vector>
using namespace std;

// n == original.size()
// runtime: O(n)
// space: O(1)
vector<vector<int>> construct_2d_array(vector<int>& original, int m, int n) {
    if (original.size() != m * n) return {};

    int p = 0;
    vector<vector<int>> result(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = original[p];
            p++;
        }
    }
    return result;
}

int main() {
    vector<int> original = {1, 2, 3, 4};
    int m = 2;
    int n = 2;
    // [[1,2],[3,4]]
    vector<vector<int>> result = construct_2d_array(original, m, n);
    for (vector<int> row : result) {
        for (int n : row) {
            cout << n << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    original = {1, 2, 3};
    m = 1;
    n = 3;
    // [[1,2,3]]
    result = construct_2d_array(original, m, n);
    for (vector<int> row : result) {
        for (int n : row) {
            cout << n << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    original = {1, 2};
    m = 1;
    n = 1;
    // []
    result = construct_2d_array(original, m, n);
    for (vector<int> row : result) {
        for (int n : row) {
            cout << n << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
