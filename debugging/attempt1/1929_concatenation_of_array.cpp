#include "debugging.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> get_concatenation(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n * 2);

    for (int i = 0; i < n; i++) result[i] = nums[i];
    for (int i = n; i < n * 2; i++) result[i] = nums[i - n];

    return result;
}

int main() {
    vector<int> result;
    vector<int> nums;

    nums = {1, 2, 1};
    result = get_concatenation(nums);
    cout << result << '\n';  // [1,2,1,1,2,1]

    nums = {1, 3, 2, 1};
    result = get_concatenation(nums);
    cout << result << '\n';  // [1,3,2,1,1,3,2,1]
}
