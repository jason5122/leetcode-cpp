#include "debugging.h"
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// n == nums.size()
// runtime: O(n)
// space: O(n)
vector<int> findDisappearedNumbers(vector<int>& nums) {
    unordered_set<int> set;

    for (int n : nums) {
        set.insert(n);
    }

    vector<int> result;
    for (int n = 1; n <= nums.size(); n++) {
        auto search = set.find(n);
        if (search == set.end()) {
            result.push_back(n);
        }
    }

    return result;
}

// USED SOLUTION
// n == nums.size()
// runtime: O(n)
// space: O(1)
vector<int> findDisappearedNumbers2(vector<int>& nums) {
    for (int n : nums) {
        int i = abs(n) - 1;
        if (nums[i] > 0) {
            nums[i] *= -1;  // mark number
        }
    }

    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            result.push_back(i + 1);
        }
    }
    return result;
}

vector<int> find_disappeared_numbers(vector<int>& nums) {
    for (int n : nums) {
        int i = abs(n) - 1;
        if (nums[i] > 0) {
            nums[i] = -nums[i];
        }
    }

    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            result.push_back(i + 1);
        }
    }
    return result;
}

int main() {
    vector<int> result;
    vector<int> nums;

    nums = {4, 3, 2, 7, 8, 2, 3, 1};
    result = find_disappeared_numbers(nums);
    cout << result << '\n';  // [5,6]

    nums = {1, 1};
    result = find_disappeared_numbers(nums);
    cout << result << '\n';  // [2]
}
