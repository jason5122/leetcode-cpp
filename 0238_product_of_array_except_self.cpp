#include <iostream>
#include <vector>
using namespace std;

// USED SOLUTION
// n == nums.size()
// runtime: O(n)
// space: O(n)
vector<int> product_except_self(vector<int>& nums) {
    int n = nums.size();

    vector<int> product_left(n, 1);
    product_left[0] = nums[0];
    for (int i = 1; i < n; i++) {
        product_left[i] = product_left[i - 1] * nums[i];
    }

    vector<int> product_right(n, 1);
    product_right[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        product_right[i] = product_right[i + 1] * nums[i];
    }

    vector<int> result(n, 1);
    for (int i = 0; i < n; i++) {
        if (i > 0) result[i] *= product_left[i - 1];
        if (i < n - 1) result[i] *= product_right[i + 1];
    }
    return result;
}

// USED SOLUTION
// n == nums.size()
// runtime: O(n)
// space: O(1)
vector<int> product_except_self2(vector<int>& nums) {
    int n = nums.size();

    vector<int> result(n, 1);
    result[0] = nums[0];
    for (int i = 1; i < n; i++) {
        result[i] = result[i - 1] * nums[i];
    }

    int product_right = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (i > 0) {
            result[i] = result[i - 1];
        } else {
            result[i] = 1;
        }
        result[i] *= product_right;

        product_right *= nums[i];
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = product_except_self2(nums);  // [24,12,8,6]
    for (int n : result) cout << n << ' ';
    cout << '\n';

    nums = {-1, 1, 0, -3, 3};
    result = product_except_self2(nums);  // [0,0,9,0,0]
    for (int n : result) cout << n << ' ';
    cout << '\n';
}
