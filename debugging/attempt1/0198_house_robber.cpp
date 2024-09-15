#include "debugging.h"
#include "leetcode.h"
using namespace std;

// n == nums.size()
// runtime: O(n)
// space: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int with = nums[i];
            if (i - 2 >= 0) with += dp[i - 2];

            int without = dp[i - 1];

            dp[i] = max(with, without);
        }
        return dp.back();
    }
};

// USED SOLUTION
// n == nums.size()
// runtime: O(n)
// space: O(1)
class Solution2 {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0;
        int prev1 = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int curr = max(prev2 + nums[i], prev1);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    Solution2 solution;
    vector<int> nums;
    int result;

    solution = Solution2();
    nums = {1, 2, 3, 1};
    result = solution.rob(nums);
    cout << result << '\n';  // 4

    solution = Solution2();
    nums = {2, 7, 9, 3, 1};
    result = solution.rob(nums);
    cout << result << '\n';  // 12
}
