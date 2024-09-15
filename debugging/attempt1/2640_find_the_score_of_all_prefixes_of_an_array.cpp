#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
2 3 7 5 10

2 + 2 = 4
4 + (3 + 3) = 10
10 + (7 + 7) = 24
24 + (5 + 7) = 36
36 + (10 + 10) = 56

n == nums.size()
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(nums[i], mx);

            if (i > 0) ans[i] = ans[i - 1];
            ans[i] += nums[i] + mx;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    vector<long long> ans;

    solution = Solution();
    nums = {2, 3, 7, 5, 10};
    ans = solution.findPrefixScore(nums);
    cout << ans << '\n';  // [4,10,24,36,56]

    solution = Solution();
    nums = {1, 1, 2, 4, 8, 16};
    ans = solution.findPrefixScore(nums);
    cout << ans << '\n';  // [2,4,8,16,32,64]
}
