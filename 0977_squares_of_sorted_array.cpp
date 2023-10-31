#include <iostream>
#include <vector>
using namespace std;

// n == nums.size()
// runtime: O(n)
// space: O(1)
vector<int> sorted_squares(vector<int>& nums) {
    vector<int> result;

    int i;
    for (i = 0; i < nums.size(); i++) {
        if (nums[i] >= 0) break;
    }
    int j = i - 1;

    // i is now pointing at the first positive number (or zero)
    // j is now pointing at the first negative number
    // NOTE: both i and j may be out of bounds

    while ((i < nums.size()) || (j >= 0)) {
        if (i >= nums.size()) {
            result.push_back(nums[j] * nums[j]);
            j--;
        } else if (j < 0) {
            result.push_back(nums[i] * nums[i]);
            i++;
        } else if (nums[i] <= abs(nums[j])) {
            result.push_back(nums[i] * nums[i]);
            i++;
        } else {
            result.push_back(nums[j] * nums[j]);
            j--;
        }
    }
    return result;
}

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = sorted_squares(nums);  // [0,1,9,16,100]
    for (int n : result) cout << n << ' ';
    cout << '\n';

    nums = {-7, -3, 2, 3, 11};
    result = sorted_squares(nums);  // [4,9,9,49,121]
    for (int n : result) cout << n << ' ';
    cout << '\n';
}
