#include "debugging.h"
#include <iostream>
#include <vector>
using namespace std;

// runtime: O(n*nCk)
// space: O(nCk)
class Solution {
    int n;
    vector<int> combination;
    vector<vector<int>> result;

    void backtrack(int k, int start) {
        if (k == 0) {
            result.push_back(combination);
            return;
        }

        for (int a = start; a <= n; a++) {
            combination.push_back(a);
            backtrack(k - 1, a + 1);
            combination.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        backtrack(k, 1);
        return result;
    }
};

int main() {
    vector<vector<int>> result;
    Solution soln;
    int n, k;

    soln = Solution();
    n = 4;
    k = 2;
    result = soln.combine(n, k);
    // [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
    cout << result << '\n';

    soln = Solution();
    n = 1;
    k = 1;
    result = soln.combine(n, k);
    cout << result << '\n';  // [[1]]
}
