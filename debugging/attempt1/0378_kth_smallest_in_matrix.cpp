#include <functional>
#include <iostream>
#include <queue>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (vector<int> row : matrix) {
        for (int n : row) {
            min_heap.push(n);
        }
    }

    for (int i = 0; i < k - 1; ++i) {
        min_heap.pop();
    }

    return min_heap.top();
}

int main() {
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;
    int result = kthSmallest(matrix, k);
    cout << result << '\n';

    matrix = {{-5}};
    k = 1;
    result = kthSmallest(matrix, k);
    cout << result << '\n';
}
