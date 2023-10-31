#include "debugging.h"
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// runtime: O(nCk)
// space: O(k)
class Solution {
    vector<vector<int>> result;
    vector<int> combination;
    unordered_set<int> used;

    void backtrack(int k, int n) {
        if (k == 0) {
            if (n == 0) result.push_back(combination);
            return;
        }

        int start = combination.empty() ? 1 : combination.back();

        for (int a = start; a <= 9; a++) {
            if (used.count(a)) continue;

            combination.push_back(a);
            used.insert(a);
            backtrack(k - 1, n - a);
            combination.pop_back();
            used.erase(a);
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n);
        return result;
    }
};

int main() {
    vector<vector<int>> result;
    Solution soln;
    int k, n;

    soln = Solution();
    k = 3;
    n = 7;
    result = soln.combinationSum3(k, n);
    cout << result << '\n';  // [[1,2,4]]

    soln = Solution();
    k = 3;
    n = 9;
    result = soln.combinationSum3(k, n);
    cout << result << '\n';  // [[1,2,6],[1,3,5],[2,3,4]]

    soln = Solution();
    k = 4;
    n = 1;
    result = soln.combinationSum3(k, n);
    cout << result << '\n';  // []
}
