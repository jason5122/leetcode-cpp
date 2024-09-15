#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
USED SOLUTION

6 7 1 2 3 4 5
l = 2
r = 1
m = n / 2 + 2 = 5

4 5 6 7 1 2 3
l = 4
r = 3
m = n / 2 + 4 = 7
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivot = find_pivot(nums);

        int l = 0, r = n - 1;

        while (l <= r) {
            int m = (l + r) / 2;
            int m_actual = normalize(m + pivot, n);

            if (nums[m_actual] < target) l = m + 1;
            else if (nums[m_actual] > target) r = m - 1;
            else return m_actual;
        }
        return -1;
    }

private:
    int find_pivot(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int l = 0, r = n - 1;

        if (nums[r] > nums[0]) return 0;  // no rotation

        while (l <= r) {
            int m = (l + r) / 2;

            if (nums[m] > nums[m + 1]) return m + 1;
            if (nums[m - 1] > nums[m]) return m;

            if (nums[m] > nums[0]) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }

    int normalize(int i, int n) {
        return (i + n) % n;
    }
};

int main() {
    Solution soln;
    vector<int> nums;
    int target;
    int ans;

    soln = Solution();
    nums = {4, 5, 6, 7, 0, 1, 2};
    target = 0;
    ans = soln.search(nums, target);
    cout << ans << '\n';  // 4

    soln = Solution();
    nums = {4, 5, 6, 7, 0, 1, 2};
    target = 3;
    ans = soln.search(nums, target);
    cout << ans << '\n';  // -1

    soln = Solution();
    nums = {1};
    target = 0;
    ans = soln.search(nums, target);
    cout << ans << '\n';  // -1
}
