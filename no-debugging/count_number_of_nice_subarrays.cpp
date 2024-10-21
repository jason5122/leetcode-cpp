/*
nums = [1,1,2,1,1], k = 3
       [1,2,2,3,4]

nums = [2,2,2,1,2,2,1,2,2,2], k = 2
       [0,0,0,1,1,1,2,2,2,2]

USED SOLUTION
n == nums.size()
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefix(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1) count++;
            prefix[i] = count;
        }

        unordered_map<int, int> odd_subarrays;
        odd_subarrays[0] = 1;

        int ans = 0;
        for (int count : prefix) {
            ans += odd_subarrays[count - k];
            odd_subarrays[count]++;
        }
        return ans;
    }
};
