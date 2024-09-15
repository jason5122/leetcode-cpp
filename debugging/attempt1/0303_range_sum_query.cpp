#include <iostream>
#include <vector>
using namespace std;

// n == right - left
// runtime: O(n)
// space: O(1)
class NumArray {
    vector<int> nums;

   public:
    NumArray(vector<int> &nums) { this->nums = nums; }

    int sum_range(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; i++) {
            sum += nums[i];
        }
        return sum;
    }
};

// USED SOLUTION
// n == nums.size()
// runtime: O(n) initialize; O(1) sum_range()
// space: O(n)
class NumArray2 {
    vector<int> cum_sum;

   public:
    NumArray2(vector<int> &nums) {
        cum_sum = vector<int>(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0) {
                cum_sum[i] += cum_sum[i - 1];
            }
            cum_sum[i] += nums[i];
        }
    }

    int sum_range(int left, int right) {
        if (left > 0) {
            return cum_sum[right] - cum_sum[left - 1];
        } else {
            return cum_sum[right];
        }
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray2 *arr = new NumArray2(nums);

    int result = arr->sum_range(0, 2);
    cout << result << '\n';  // 1

    result = arr->sum_range(2, 5);
    cout << result << '\n';  // -1

    result = arr->sum_range(0, 5);
    cout << result << '\n';  // -3
}
