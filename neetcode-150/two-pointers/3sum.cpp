/*
n == nums.size()
runtime: O(n^2)
space: O(2n)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int size = nums.size();

        vector<vector<int>> result;
        for (int i = 0; i < size - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // prevent duplicates

            // two sum
            int target = -nums[i];
            unordered_map<int, int> hm;
            unordered_set<int> seen;
            for (int j = i + 1; j < size; j++) {
                if (seen.count(nums[j])) continue;

                if (hm.count(nums[j])) {
                    result.push_back({nums[i], nums[hm[nums[j]]], nums[j]});
                    seen.insert(nums[j]);
                } else {
                    int complement = target - nums[j];
                    hm[complement] = j;
                }
            }
        }
        return result;
    }
};

/*
n == nums.size()
runtime: O(n^2)
space: O(1)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int size = nums.size();

        vector<vector<int>> result;
        for (int i = 0; i < size - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // prevent duplicates

            // two sum sorted
            int target = -nums[i];
            int l = i + 1;
            int r = size - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum < target) {
                    l++;
                } else if (sum > target) {
                    r--;
                } else {
                    result.push_back({nums[i], nums[l], nums[r]});

                    do l++;
                    while (l < size && nums[l] == nums[l - 1]);  // prevent duplicates
                }
            }
        }
        return result;
    }
};

/*
n == nums.size()
runtime: O(n^2)
space: O(n)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int size = nums.size();

        vector<vector<int>> result;
        for (int i = 0; i < size - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // prevent duplicates

            // two sum
            int target = -nums[i];
            unordered_map<int, int> hm;
            for (int j = i + 1; j < size; j++) {
                if (hm.count(nums[j])) {
                    result.push_back({nums[i], nums[hm[nums[j]]], nums[j]});

                    do j++;
                    while (j < size && nums[j] == nums[j - 1]);
                    j--;  // counteract for loop increment
                } else {
                    int complement = target - nums[j];
                    hm[complement] = j;
                }
            }
        }
        return result;
    }
};
