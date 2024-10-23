#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
USED HINT
n == # of elements in nums
runtime: O(n*lg(n))
space: O(n)
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

/*
USED PARTIAL SOLUTION
n == # of elements in nums
runtime: O(n)
space: O(sqrt(n))
*/
class Solution2 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int, int>> q;
        unordered_map<int, unordered_map<int, bool>> visited;

        q.push({0, 0});
        visited[0][0] = true;

        auto exists = [&](int r, int c) {
            int rows = nums.size();
            int cols = nums[r].size();
            return (0 <= r && r < rows) && (0 <= c && c < cols);
        };

        vector<int> ans;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            ans.emplace_back(nums[r][c]);

            if (exists(r + 1, c) && !visited[r + 1][c]) {
                q.push({r + 1, c});
                visited[r + 1][c] = true;
            }
            if (exists(r, c + 1) && !visited[r][c + 1]) {
                q.push({r, c + 1});
                visited[r][c + 1] = true;
            }
        }
        return ans;
    }
};

/*
USED PARTIAL SOLUTION
n == # of elements in nums
runtime: O(n)
space: O(n)
*/
class Solution3 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<pair<int, int>>> diagonals;
        for (int r = nums.size() - 1; r >= 0; r--) {
            for (int c = 0; c < nums[r].size(); c++) {
                int d = r + c;
                diagonals[d].push_back({r, c});
            }
        }

        vector<int> ans;
        int d = 0;
        while (diagonals.count(d)) {
            for (auto& [r, c] : diagonals[d]) {
                ans.push_back(nums[r][c]);
            }
            d++;
        }
        return ans;
    }
};

/*
USED PARTIAL SOLUTION
n == # of elements in nums
runtime: O(n)
space: O(sqrt(n))
*/
class Solution4 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<int> ans;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            ans.emplace_back(nums[r][c]);

            if (c == 0 && r + 1 < nums.size()) {
                q.push({r + 1, c});
            }
            if (c + 1 < nums[r].size()) {
                q.push({r, c + 1});
            }
        }
        return ans;
    }
};

int main() {
    Solution4 soln;
    vector<vector<int>> nums;
    vector<int> ans;

    soln = Solution4{};
    nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    ans = soln.findDiagonalOrder(nums);

    // [1,4,2,7,5,3,8,6,9]
    for (int k : ans) cout << k << ' ';
    cout << '\n';
}
