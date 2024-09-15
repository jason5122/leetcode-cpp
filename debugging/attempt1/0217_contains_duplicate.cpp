#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int n : nums) {
        if (seen.find(n) != seen.end()) {
            return true;
        } else {
            seen.insert(n);
        }
    }

    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    bool result = containsDuplicate(nums);
    cout << result << '\n';  // true
}
