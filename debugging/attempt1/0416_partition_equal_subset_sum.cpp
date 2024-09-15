#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
dp[i][j] = dp[i + 1][j] || dp[i + 1][j - nums[i]]

nums = [1,5,11,5]
sum = 22

1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0
1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0

nums = [1,2,5]
sum = 8
1,0,1,1,0,1,0,1,1
1,0,1,0,0,1,0,1,0
1,0,0,0,0,1,0,0,0
1,0,0,0,0,0,0,0,0

n == nums.size()
sum = accumulate(nums)
runtime: O(n*sum)
space: O(n*sum)
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        if (sum % 2 == 1) return false;

        // Base case.
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Fill in sub-problems.
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i + 1][j];
                if (j - nums[i] >= 0) {
                    dp[i][j] = dp[i][j] || dp[i + 1][j - nums[i]];
                }
            }
        }

        return dp[0][sum / 2];
    }
};

int main() {
    Solution soln;
    vector<int> nums;
    bool ans;

    soln = Solution{};
    nums = {1, 2, 5};
    ans = soln.canPartition(nums);
    cout << ans << '\n';  // 0
}
