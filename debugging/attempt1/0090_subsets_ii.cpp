#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // n == nums.size()
    // runtime: O(n*2^n)
    // space: O(n*2^n)
    vector<vector<int>> subsets_with_dup(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<int> unique;
        for (int n : nums) {
            if (!freq.count(n)) {
                freq[n] = 0;
                unique.push_back(n);
            }
            freq[n]++;
        }

        vector<vector<int>> result;

        result.push_back({});
        for (int n : unique) {
            vector<vector<int>> temp;
            for (vector<int> v : result) {
                vector<int> subset = v;
                for (int i = 0; i < freq[n]; i++) {
                    subset.push_back(n);
                    temp.push_back(subset);
                }
            }
            result.insert(result.end(), temp.begin(), temp.end());
        }
        return result;
    }
};

void print_subsets(vector<vector<int>> subsets) {
    for (vector<int> subset : subsets) {
        cout << '[';
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i != subset.size() - 1) cout << ',';
        }
        cout << "] ";
    }
    cout << '\n';
}

int main() {
    Solution s1;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = s1.subsets_with_dup(nums);
    // [[],[1],[1,2],[1,2,2],[2],[2,2]]
    print_subsets(result);

    Solution s2;
    nums = {0};
    result = s2.subsets_with_dup(nums);  // [[],[0]]
    print_subsets(result);
}
