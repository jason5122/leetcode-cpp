#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // n == nums.size()
    // runtime: O(n*2^n)
    // space: O(n*2^n)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({});
        for (int n : nums) {
            vector<vector<int>> temp;
            for (vector<int> v : result) {
                vector<int> subset = v;
                subset.push_back(n);
                temp.push_back(subset);
            }
            result.insert(result.end(), temp.begin(), temp.end());
        }
        return result;
    }
};

class Solution2 {
    int n;
    vector<vector<int>> result;

    void helper(vector<int>& nums, vector<int> subset, int i) {
        if (i == n) {
            result.push_back(subset);
            return;
        }

        helper(nums, subset, i + 1);
        subset.push_back(nums[i]);
        helper(nums, subset, i + 1);
    }

public:
    // n == nums.size()
    // runtime: O(n*2^n)
    // space: O(n*2^n)
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        helper(nums, {}, 0);
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
    vector<vector<int>> result = s1.subsets(nums);
    // [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
    print_subsets(result);

    Solution2 s2;
    nums = {0};
    result = s2.subsets(nums);  // [[],[0]]
    print_subsets(result);
}
