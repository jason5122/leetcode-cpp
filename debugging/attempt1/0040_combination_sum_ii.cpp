#include "debugging.h"
#include <iostream>
#include <vector>
using namespace std;

// USED SOLUTION
// n == candidates.size()
// runtime: O(n*2^n)
// space: O(n*2^n)?
class Solution {
    vector<vector<int>> result;
    vector<int> candidates;
    unordered_map<int, int> freqs;

    void backtrack(int i, int remaining, vector<int> used) {
        if (remaining <= 0) {
            if (remaining == 0) result.push_back(used);
            return;
        }
        if (i == candidates.size()) return;

        int freq = freqs[candidates[i]];

        backtrack(i + freq, remaining, used);

        vector<int> new_used = used;
        for (int j = 0; j < freq; j++) {
            new_used.push_back(candidates[i]);
            remaining -= candidates[i];
            backtrack(i + freq, remaining, new_used);
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->candidates = candidates;
        sort(this->candidates.begin(), this->candidates.end());

        for (int n : candidates) freqs[n]++;

        backtrack(0, target, {});
        return result;
    }
};

// n == candidates.size()
// runtime: O(2^n)
// space: O(n)
class Solution2 {
    vector<vector<int>> result;
    vector<int> candidates;
    unordered_map<int, int> freqs;
    vector<int> combination;

    void backtrack(int i, int remaining) {
        if (remaining <= 0) {
            if (remaining == 0) result.push_back(combination);
            return;
        }
        if (i == candidates.size()) return;

        int freq = freqs[candidates[i]];

        backtrack(i + freq, remaining);

        for (int j = 0; j < freq; j++) {
            combination.push_back(candidates[i]);
            remaining -= candidates[i];
            backtrack(i + freq, remaining);
        }
        for (int j = 0; j < freq; j++) combination.pop_back();
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->candidates = candidates;
        sort(this->candidates.begin(), this->candidates.end());

        for (int n : candidates) freqs[n]++;

        backtrack(0, target);
        return result;
    }
};

int main() {
    Solution2 soln;
    vector<vector<int>> result;
    vector<int> candidates;
    int target;

    soln = Solution2();
    candidates = {10, 1, 2, 7, 6, 1, 5};
    target = 8;
    result = soln.combinationSum2(candidates, target);
    cout << result << '\n';  // [[1,1,6],[1,2,5],[1,7],[2,6]]

    soln = Solution2();
    candidates = {2, 5, 2, 1, 2};
    target = 5;
    result = soln.combinationSum2(candidates, target);
    cout << result << '\n';  // [[1,2,2],[5]]
}
