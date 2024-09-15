#include "debugging.h"
#include "leetcode.h"
using namespace std;

// WRONG
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];

        vector<int> dp(size, 0);
        vector<bool> robbed_first(size, false);
        dp[0] = nums[0];
        robbed_first[0] = true;
        dp[1] = max(nums[0], nums[1]);
        robbed_first[1] = nums[0] > nums[1] ? true : false;

        for (int i = 2; i < size; i++) {
            int prev2 = dp[i - 2] + nums[i];
            int prev1 = dp[i - 1];

            if (i == size - 1 && robbed_first[i - 2]) prev2 -= nums[i];

            if (i == size - 1) {
                int alternate = dp[i - 2] - nums[0] + nums[i];
                prev2 = max(alternate, prev2);
            }

            printf("%d: %d %d\n", i, prev2, prev1);

            if (prev2 > prev1) {
                dp[i] = prev2;
                robbed_first[i] = robbed_first[i - 2];
            } else {
                dp[i] = prev1;
                robbed_first[i] = robbed_first[i - 1];
            }
        }
        cout << dp << '\n';
        cout << robbed_first << '\n';
        return max(dp[size - 1], dp[size - 2]);
    }
};

// WRONG
class Solution2 {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];

        vector<int> dp(size - 1, 0);
        dp[0] = max(nums[0], nums[size - 1]);
        if (size > 3) {
            dp[1] = max(nums[0], nums[1] + nums[size - 1]);
        } else {
            dp[1] = max(nums[0], nums[1]);
        }

        for (int i = 2; i < size - 1; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        cout << dp << '\n';
        return max(dp[size - 2], dp[size - 3]);
    }
};

/*
USED SOLUTION
n == nums.size()
runtime: O(2n)
space: O(2n)
*/
class Solution3 {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        if (size == 2) return max(nums[0], nums[1]);

        return max(helper(nums, 0, size - 1), helper(nums, 1, size));
    }

private:
    int helper(vector<int>& nums, int start, int end) {
        vector<int> dp(end - start, 0);

        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[1 + start]);

        for (int i = 2 + start; i < end; i++) {
            dp[i - start] = max(dp[i - start - 2] + nums[i], dp[i - start - 1]);
        }
        return dp.back();
    }
};

int main() {
    Solution3 soln;
    vector<int> nums;
    int ans;

    soln = Solution3();
    nums = {2, 3, 2};
    ans = soln.rob(nums);
    cout << ans << '\n';  // 3

    soln = Solution3();
    nums = {1, 2, 3, 1};
    ans = soln.rob(nums);
    cout << ans << '\n';  // 4

    soln = Solution3();
    nums = {1, 2, 3};
    ans = soln.rob(nums);
    cout << ans << '\n';  // 3

    // USED SOLUTION
    soln = Solution3();
    nums = {2, 2, 4, 3, 2, 5};
    ans = soln.rob(nums);
    cout << ans << '\n';  // 10

    // USED SOLUTION
    soln = Solution3();
    nums = {1, 3, 1, 3, 100};
    ans = soln.rob(nums);
    cout << ans << '\n';  // 103

    // USED SOLUTION
    soln = Solution3();
    nums = {200, 3, 140, 20, 10};
    ans = soln.rob(nums);
    cout << ans << '\n';  // 340
}
