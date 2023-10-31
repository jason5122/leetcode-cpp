/*
target = 4
[1, 2, 3, 4, 5]

target = 1
[1]

n == nums.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();

        int l = 0;
        int r = size - 1;
        while (l <= r) {
            int m = (l + r) / 2;

            if (nums[m] < target) l++;
            else if (nums[m] > target) r--;
            else return m;
        }
        return -1;
    }
};

/*
USED SOLUTION
n == nums.size()
runtime: O(lg(n))
space: O(1)
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();

        int l = 0;
        int r = size - 1;
        while (l <= r) {
            int m = (l + r) / 2;

            if (nums[m] < target) l = m + 1;
            else if (nums[m] > target) r = m - 1;
            else return m;
        }
        return -1;
    }
};
