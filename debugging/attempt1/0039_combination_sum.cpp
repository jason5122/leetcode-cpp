#include "debugging.h"
#include <iostream>
#include <vector>
using namespace std;

// n == candidates.size()
// t == target
// m == min # in candidates
// runtime: O(n^(t/m))
// space: O(t/m)
class Solution {
    vector<vector<int>> result;
    vector<int> candidates;

    void backtrack(int start, int remaining, vector<int> used) {
        if (remaining == 0) {
            result.push_back(used);
            return;
        }

        // avoid backtracking on elements before start to prevent duplicates
        for (int i = start; i < candidates.size(); i++) {
            int n = candidates[i];

            if (n <= remaining) {
                vector<int> nums_new = used;
                nums_new.push_back(n);
                backtrack(i, remaining - n, nums_new);
            }
        }
    }

public:
    vector<vector<int>> combination_sum(vector<int>& candidates, int target) {
        this->candidates = candidates;
        backtrack(0, target, {});
        return result;
    }
};

int main() {
    Solution soln;
    vector<vector<int>> result;
    vector<int> candidates;
    int target;

    soln = Solution();
    candidates = {2, 3, 6, 7};
    target = 7;
    result = soln.combination_sum(candidates, target);
    cout << result << '\n';  // [[2,2,3],[7]]

    soln = Solution();
    candidates = {2, 3, 5};
    target = 8;
    result = soln.combination_sum(candidates, target);
    cout << result << '\n';  // [[2,2,2,2],[2,3,3],[3,5]]

    soln = Solution();
    candidates = {2, 3, 6, 7};
    target = 7;
    result = soln.combination_sum(candidates, target);
    cout << result << '\n';  // [[2,2,3],[7]]
}
