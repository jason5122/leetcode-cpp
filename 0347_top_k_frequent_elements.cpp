#include "debugging.h"
#include <queue>
#include <vector>
using namespace std;

// n == nums.size()
// runtime: O(n*lg n)
// space: O(n)
vector<int> top_k_frequent(vector<int>& nums, int k) {
    unordered_map<int, int> freqs;
    for (int n : nums) freqs[n]++;

    vector<pair<int, int>> entries(freqs.begin(), freqs.end());
    sort(entries.begin(), entries.end(),
         [](auto& pair1, auto& pair2) { return pair1.second > pair2.second; });

    vector<int> result;
    for (int i = 0; i < k; i++) result.push_back(entries[i].first);
    return result;
}

// USED SOLUTION
// runtime: O(n)
// space: O(n)
vector<int> top_k_frequent2(vector<int>& nums, int k) {
    unordered_map<int, int> freqs;
    for (int n : nums) freqs[n]++;

    vector<pair<int, int>> entries(freqs.begin(), freqs.end());

    vector<vector<int>> counts(nums.size() + 1);
    for (pair<int, int>& entry : entries) {
        counts[entry.second].push_back(entry.first);
    }

    vector<int> result;
    for (int i = counts.size() - 1; i >= 0; i--) {
        if (k == 0) break;

        while (!counts[i].empty()) {
            int n = counts[i].back();
            counts[i].pop_back();
            result.push_back(n);
            k--;
        }
    }
    return result;
}

int main() {
    vector<int> result;
    vector<int> nums;
    int k;

    nums = {1, 1, 1, 2, 2, 3};
    k = 2;
    result = top_k_frequent2(nums, k);
    cout << result << '\n';  // [1,2]

    nums = {1};
    k = 1;
    result = top_k_frequent2(nums, k);
    cout << result << '\n';  // [1]

    // USED SOLUTION
    nums = {1, 2};
    k = 2;
    result = top_k_frequent2(nums, k);
    cout << result << '\n';  // [1,2]
}
