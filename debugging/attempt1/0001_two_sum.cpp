#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// n == nums.size()
// runtime: O(n)
// space: O(n)
vector<int> two_sum(vector<int>& nums, int target) {
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
        int n = nums[i];
        if (map.find(n) != map.end()) return {map[n], i};

        int complement = target - nums[i];
        map[complement] = i;
    }
    return {-1, -1};  // no solution
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = two_sum(nums, target);  // [0,1]
    for (int n : result) cout << n << ' ';
    cout << '\n';

    nums = {3, 2, 4};
    target = 6;
    result = two_sum(nums, target);  // [1,2]
    for (int n : result) cout << n << ' ';
    cout << '\n';

    nums = {3, 3};
    target = 6;
    result = two_sum(nums, target);  // [0,1]
    for (int n : result) cout << n << ' ';
    cout << '\n';
}
