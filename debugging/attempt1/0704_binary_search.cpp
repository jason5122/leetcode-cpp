#include <iostream>
#include <vector>
using namespace std;

// n == nums.size()
// runtime: O(log n)
// space: O(1)
int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (nums[mid] < target) {
            low = mid + 1;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int result = search(nums, target);  // 4
    cout << result << '\n';

    nums = {-1, 0, 3, 5, 9, 12};
    target = 2;
    result = search(nums, target);  // -1
    cout << result << '\n';
}
