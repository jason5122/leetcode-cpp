/*
USED TEST CASE
nums = [-108,-108,-517]
answer = -517

TIME LIMIT EXCEEDED
n == nums.size()
runtime: O(n^2)
space: O(1)
*/
class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int max_outlier = INT_MIN;
        for (int i = 0; i < n; i++) {
            int outlier = nums[i];
            int new_sum = sum - outlier;  // Remove a candidate outlier.
            for (int j = 0; j < n; j++) {
                if (j == i) continue;

                int special_sum = nums[j];
                if (new_sum - special_sum == special_sum) {
                    max_outlier = max(outlier, max_outlier);
                }
            }
        }
        return max_outlier;
    }
};

/*
USED HINTS
n == nums.size()
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        unordered_map<int, int> freqs;
        for (int k : nums) freqs[k]++;

        int max_outlier = INT_MIN;
        for (int i = 0; i < n; i++) {
            // Remove a candidate outlier.
            int outlier = nums[i];
            int new_sum = sum - outlier;
            freqs[outlier]--;
            if (freqs[outlier] == 0) freqs.erase(outlier);

            if (new_sum % 2 == 0) {
                int special_sum = new_sum / 2;
                if (freqs.count(special_sum)) {
                    max_outlier = max(outlier, max_outlier);
                }
            }

            // Restore the outlier.
            freqs[outlier]++;
        }
        return max_outlier;
    }
};
