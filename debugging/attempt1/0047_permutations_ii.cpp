#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int i) {
        if (i == nums.size()) {
            result.push_back(nums);
            return;
        }

        unordered_set<int> seen;
        for (int j = i; j < nums.size(); j++) {
            if (seen.count(nums[j])) continue;
            seen.insert(nums[j]);

            swap(nums[i], nums[j]);
            backtrack(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }

public:
    // n == nums.size()
    // runtime: O(n!)
    // space: O(n!)
    vector<vector<int>> permute_unique(vector<int>& nums) {
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
    Solution s1;
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = s1.permute_unique(nums);
    // [[1,1,2],[1,2,1],[2,1,1]]
    print_subsets(result);

    Solution s2;
    nums = {1, 2, 3};
    result = s2.permute_unique(nums);
    // [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    print_subsets(result);

    // USED SOLUTION
    Solution s3;
    nums = {2, 2, 1, 1};
    result = s3.permute_unique(nums);
    // [[1,1,2,2],[1,2,1,2],[1,2,2,1],[2,1,1,2],[2,1,2,1],[2,2,1,1]]
    print_subsets(result);
}
