/*
USED TEST CASE
nums = [7,0,9,6,9,6,1,7,9,0,1,2,9,0,3]
ans = 2

n == nums.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        int i = 0;
        while (i < n - 1) {
            int max_jump = 0;
            int end = i + nums[i];

            if (end >= n - 1) {
                ans++;
                break;
            }

            for (int j = i; j <= end; j++) {
                int jump = j + nums[j];
                if (jump > max_jump) {
                    max_jump = jump;
                    i = j;
                }
            }
            ans++;
        }
        return ans;
    }
};
