#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
USED HINT
m == nums.size()
n == # of columns on average
runtime: O(m*n)
space: O(m*n)
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        using p = pair<int, int>;

        auto compare = [](auto& p1, auto& p2) {
            int sum1 = p1.first + p1.second;
            int sum2 = p2.first + p2.second;
            if (sum2 == sum1) {
                return p2.first > p1.first || p2.second < p1.second;
            } else {
                return sum2 < sum1;
            }
        };

        priority_queue<p, vector<p>, decltype(compare)> pq;
        for (int r = 0; r < nums.size(); r++) {
            for (int c = 0; c < nums[r].size(); c++) {
                pq.push({r, c});
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            auto [r, c] = pq.top();
            pq.pop();
            ans.emplace_back(nums[r][c]);
        }
        return ans;
    }
};

int main() {
    Solution soln;
    vector<vector<int>> nums;
    vector<int> ans;

    soln = Solution{};
    nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    ans = soln.findDiagonalOrder(nums);

    // [1,4,2,7,5,3,8,6,9]
    for (int k : ans) cout << k << ' ';
    cout << '\n';
}
