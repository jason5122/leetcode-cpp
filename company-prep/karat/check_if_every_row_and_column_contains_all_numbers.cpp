/*
n == matrix.size()
runtime: O(n^2)
space: O(n)
*/
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Check rows.
        for (int r = 0; r < n; r++) {
            unordered_set<int> seen;
            for (int c = 0; c < n; c++) {
                seen.insert(matrix[r][c]);
            }
            if (seen.size() < n) return false;
        }

        // Check columns.
        for (int c = 0; c < n; c++) {
            unordered_set<int> seen;
            for (int r = 0; r < n; r++) {
                seen.insert(matrix[r][c]);
            }
            if (seen.size() < n) return false;
        }

        return true;
    }
};
