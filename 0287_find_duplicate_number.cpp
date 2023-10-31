#include <iostream>
#include <vector>
using namespace std;

// USED SOLUTION
// n == nums.size()
// runtime: O(n)
// space: O(1)
int find_duplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    int result = find_duplicate(nums);  // 2
    cout << result << '\n';

    nums = {3, 1, 3, 4, 2};
    result = find_duplicate(nums);  // 3
    cout << result << '\n';
}
