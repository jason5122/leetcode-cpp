#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

// m == nums1.size()
// n == nums2.size()
// runtime: O(m*n)
// space: O(1)
vector<int> next_greater_element(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    for (int i = 0; i < nums1.size(); i++) {
        int target = nums1[i];
        int next_greatest = -1;

        int j = 0;
        while (nums2[j] != target) j++;

        for (; j < nums2.size(); j++) {
            if (nums2[j] > target) {
                next_greatest = nums2[j];
                break;
            }
        }
        result.push_back(next_greatest);
    }
    return result;
}

// USED SOLUTION
// m == nums1.size()
// n == nums2.size()
// runtime: O(2n+m)
// space: O(n)
vector<int> next_greater_element2(vector<int>& nums1, vector<int>& nums2) {
    stack<int> mono;  // monotonically decreasing
    unordered_map<int, int> map;

    for (int n : nums2) {
        while (!mono.empty() && n > mono.top()) {
            map[mono.top()] = n;
            mono.pop();
        }
        mono.push(n);
    }

    while (!mono.empty()) {
        map[mono.top()] = -1;
        mono.pop();
    }

    vector<int> result;
    for (int n : nums1) result.push_back(map[n]);
    return result;
}

int main() {
    vector<int> nums1;
    vector<int> nums2;
    vector<int> result;

    nums1 = {4, 1, 2};
    nums2 = {1, 3, 4, 2};
    result = next_greater_element2(nums1, nums2);  // [-1,3,-1]
    for (int n : result) cout << n << ' ';
    cout << '\n';

    nums1 = {2, 4};
    nums2 = {1, 2, 3, 4};
    result = next_greater_element2(nums1, nums2);  // [3,-1]
    for (int n : result) cout << n << ' ';
    cout << '\n';
}
