#include "debugging.h"
#include "leetcode.h"
using namespace std;

class Solution {
    vector<int> nums;
    int target;

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;
        return helper(0, 0);
    }

private:
    int helper(int i, int total) {
        if (i == nums.size()) return total == target;

        return helper(i + 1, total - nums[i]) + helper(i + 1, total + nums[i]);
    }
};

int main() {
    Solution soln;
    vector<int> nums;
    int target;
    int ans;

    soln = Solution();
    nums = {1, 1, 1, 1, 1};
    target = 3;
    ans = soln.findTargetSumWays(nums, target);
    cerr << ans << '\n';
}
