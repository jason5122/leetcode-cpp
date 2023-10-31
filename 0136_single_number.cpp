#include <iostream>
#include <vector>
using namespace std;

// USED SOLUTION
// n == nums.size()
// runtime: O(n)
// space: O(1)
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int n : nums) {
        result ^= n;
    }
    return result;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    int result = singleNumber(nums);
    cout << result << '\n';  // 4
}
