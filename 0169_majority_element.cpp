#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// n == nums.size()
// runtime: O(n)
// space: O(n)
int majority_element(vector<int>& nums) {
    unordered_map<int, int> freq;

    int majority = nums.size() / 2;
    for (int n : nums) {
        if (!freq.count(n)) freq[n] = 0;

        freq[n]++;
        if (freq[n] > majority) return n;
    }
    return 0;  // no solution
}

// USED SOLUTION
// n == nums.size()
// runtime: O(n)
// space: O(1)
int majority_element2(vector<int>& nums) {
    int count = 0;
    int candidate;
    for (int n : nums) {
        if (!count) candidate = n;

        count += (n == candidate) ? 1 : -1;
    }
    return candidate;
}

int main() {
    vector<int> nums = {3, 2, 3};
    int result = majority_element2(nums);  // 3
    cout << result << '\n';

    nums = {2, 2, 1, 1, 1, 2, 2};
    result = majority_element2(nums);  // 2
    cout << result << '\n';

    // USED SOLUTION
    nums = {3, 3, 4};
    result = majority_element2(nums);  // 3
    cout << result << '\n';
}
