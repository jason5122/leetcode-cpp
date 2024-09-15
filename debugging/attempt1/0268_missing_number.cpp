#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

// n == nums.size()
// runtime: O(n)
// space: O(n)
int missingNumber(vector<int>& nums) {
    unordered_set<int> set;
    for (int i = 0; i <= nums.size(); i++) {
        set.insert(i);
    }

    for (int n : nums) {
        set.erase(n);
    }

    return *set.begin();
}

// n == nums.size()
// runtime: O(n)
// space: O(1)
int missingNumber2(vector<int>& nums) {
    int nums_sum = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    int sum = n * (n + 1) / 2;

    return sum - nums_sum;
}

int main() {
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int result = missingNumber2(nums);
    cout << result << '\n';  // 8
}
