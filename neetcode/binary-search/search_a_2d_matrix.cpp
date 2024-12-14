/*
m == matrix.size()
n == matrix[0].size()
runtime: O(lg(m*n))
space: O(1)
*/
class Solution {
    pair<int, int> convert_to_index(int m, int n, int mid) {
        int r = mid / n;
        int c = mid - (n * r);
        return {r, c};
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = m * n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            auto [r, c] = convert_to_index(m, n, mid);
            if (matrix[r][c] < target) {
                low = mid + 1;
            } else if (matrix[r][c] > target) {
                high = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
