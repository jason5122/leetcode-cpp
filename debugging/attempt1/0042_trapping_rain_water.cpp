#include "debugging.h"
#include "leetcode.h"
using namespace std;

// n == height.size()
// runtime: O(2n)
// space: O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;

        stack<int> stk;
        int floor = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!stk.empty() && height[i] >= height[stk.top()]) {
                // if non-adjacent, we can trap water
                if (i > stk.top() + 1) {
                    int w = (i - stk.top()) - 1;
                    int h = min(height[i], height[stk.top()]) - floor;
                    total += w * h;
                }

                floor = height[stk.top()];
                stk.pop();
            }

            // one more iteration
            if (!stk.empty()) {
                if (i > stk.top() + 1) {
                    int w = (i - stk.top()) - 1;
                    int h = min(height[i], height[stk.top()]) - floor;
                    total += w * h;
                }
            }

            stk.push(i);
        }
        return total;
    }
};

/*
USED SOLUTION
n == height.size()
runtime: O(n^2)
space: O(1)
*/
class Solution2 {
public:
    int trap(vector<int>& height) {
        int total = 0;
        for (int i = 0; i < height.size(); i++) {
            int left_max = *max_element(height.begin(), height.begin() + i + 1);
            int right_max = *max_element(height.begin() + i, height.end());

            total += min(left_max, right_max) - height[i];
        }
        return total;
    }
};

int main() {
    Solution2 solution;
    vector<int> height;
    int result;

    solution = Solution2();
    height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    result = solution.trap(height);
    cout << result << '\n';  // 6

    solution = Solution2();
    height = {4, 2, 0, 3, 2, 5};
    result = solution.trap(height);
    cout << result << '\n';  // 9
}
