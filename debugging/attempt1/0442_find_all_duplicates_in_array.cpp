#include <iostream>
#include <vector>
using namespace std;

// USED SOLUTION
// runtime: O(n)
// space: O(1)
vector<int> find_duplicates(vector<int>& nums) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        int n = abs(nums[i]);
        if (nums[n - 1] < 0) {
            result.push_back(n);
        } else {
            nums[n - 1] *= -1;
        }
    }
    return result;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = find_duplicates(nums);  // [2,3]
    for (int n : result) cout << n << ' ';
    cout << '\n';

    nums = {1, 1, 2};
    result = find_duplicates(nums);  // [1]
    for (int n : result) cout << n << ' ';
    cout << '\n';

    nums = {1};
    result = find_duplicates(nums);  // []
    for (int n : result) cout << n << ' ';
    cout << '\n';
}
