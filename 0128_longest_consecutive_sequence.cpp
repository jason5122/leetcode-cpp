#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// USED SOLUTION
// n == nums.size()
// runtime: O(n)
// space: O(n)
int longest_consecutive(vector<int>& nums) {
    unordered_set<int> set;
    for (int n : nums) set.insert(n);

    int longest = 0;
    for (int n : nums) {
        if (!set.count(n - 1)) {
            int curr = n;
            int streak = 1;
            while (set.count(curr + 1)) {
                curr++;
                streak++;
            }
            longest = max(streak, longest);
        }
    }
    return longest;
}

// USED SOLUTION
// n == nums.size()
// runtime: O(n)
// space: O(n)
int longest_consecutive2(vector<int>& nums) {
    unordered_set<int> num_set(nums.begin(), nums.end());

    int longest_streak = 0;
    for (int n : num_set) {
        if (num_set.count(n - 1)) continue;

        int streak = 1;
        while (num_set.count(n + 1)) {
            num_set.erase(n + 1);
            streak++;
            n++;
        }
        longest_streak = max(streak, longest_streak);
    }
    return longest_streak;
}

int main() {
    int result;
    vector<int> nums;

    nums = {100, 4, 200, 1, 3, 2};
    result = longest_consecutive2(nums);
    cout << result << '\n';  // 4

    nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    result = longest_consecutive2(nums);
    cout << result << '\n';  // 9
}
