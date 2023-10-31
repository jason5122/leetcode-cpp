#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
n == nums.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int jump = nums[i];
        while (i < n - 1) {
            int old_i = i;

            for (int j = i; j <= min(i + jump, n - 1); j++) {
                if (j + nums[j] > i + jump) {
                    i = j;
                    jump = nums[j];
                }
            }

            if (i + jump >= n - 1) return true;
            if (i == old_i) return false;
        }
        return true;
    }
};

int main() {
    cout << boolalpha;

    Solution solution;
    vector<int> nums;
    bool ans;

    solution = Solution();
    nums = {2, 3, 1, 1, 4};
    ans = solution.canJump(nums);
    cout << ans << '\n';  // true

    solution = Solution();
    nums = {3, 2, 1, 0, 4};
    ans = solution.canJump(nums);
    cout << ans << '\n';  // false

    // USED SOLUTION
    solution = Solution();
    nums = {1, 2};
    ans = solution.canJump(nums);
    cout << ans << '\n';  // true

    // USED SOLUTION
    solution = Solution();
    nums = {2, 0};
    ans = solution.canJump(nums);
    cout << ans << '\n';  // true
}
