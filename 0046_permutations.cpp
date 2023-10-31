#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> result;

    void backtrack(vector<int> permutation, vector<int>& nums,
                   unordered_set<int>& seen) {
        if (seen.size() == nums.size()) {
            result.push_back(permutation);
            return;
        }

        for (int n : nums) {
            if (seen.count(n)) continue;

            permutation.push_back(n);
            seen.insert(n);
            backtrack(permutation, nums, seen);
            permutation.pop_back();
            seen.erase(n);
        }
    }

public:
    // n == nums.size()
    // runtime: O(n!)
    // space: O(n!)
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> seen;
        backtrack({}, nums, seen);
        return result;
    }
};

class Solution2 {
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int i) {
        if (i == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            backtrack(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }

public:
    // USED SOLUTION
    // n == nums.size()
    // runtime: O(n!)
    // space: O(n!)
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
};

void print_subsets(vector<vector<int>> subsets) {
    for (vector<int> subset : subsets) {
        cout << '[';
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i != subset.size() - 1) cout << ',';
        }
        cout << "] ";
    }
    cout << '\n';
}

int main() {
    Solution2 s1;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = s1.permute(nums);
    // [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    print_subsets(result);

    Solution2 s2;
    nums = {0, 1};
    result = s2.permute(nums);  // [[0,1],[1,0]]
    print_subsets(result);

    Solution2 s3;
    nums = {1};
    result = s3.permute(nums);  // [[1]]
    print_subsets(result);
}
