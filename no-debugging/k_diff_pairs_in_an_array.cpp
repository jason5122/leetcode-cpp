/*
USED PARTIAL SOLUTION
n == nums.size()
runtime: O(n*lg(n))
space: O(1)
*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int ans = 0;
        int l = 0;
        int r = 1;
        while (r < n) {
            if (l == r) r++;
            if (r >= n) break;

            if (nums[r] - nums[l] < k) {
                r++;
            } else if (nums[r] - nums[l] > k) {
                l++;
            } else {
                ans++;
                r++;

                // Skip duplicates.
                while (r < n && nums[r] == nums[r - 1]) r++;
            }
        }
        return ans;
    }
};

/*
n == nums.size()
runtime: O(n*lg(n))
space: O(1)
*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> hmap;
        for (int a : nums) hmap[a]++;

        sort(nums.begin(), nums.end());

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Exclude current number from the search.
            hmap[nums[i]]--;
            if (hmap[nums[i] + k]) ans++;
            hmap[nums[i]]++;
        }
        return ans;
    }
};
