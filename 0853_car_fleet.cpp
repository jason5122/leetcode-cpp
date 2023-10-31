#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
0 2 4     10
2 3 1

USED SOLUTION
n == position.size() == speed.size()
runtime: O(n*lg(n) + 2n)
space: O(n)
*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        transform(position.begin(), position.end(), speed.begin(), back_inserter(cars),
                  [](int a, int b) { return make_pair(a, b); });
        sort(cars.begin(), cars.end());

        stack<double> stk;
        for (const auto& car : cars) {
            double time = static_cast<double>(target - car.first) / car.second;
            while (!stk.empty() && time >= stk.top()) {
                stk.pop();
            }
            stk.push(time);
        }
        return stk.size();
    }
};

int main() {
    Solution solution;
    int target;
    vector<int> position, speed;
    int ans;

    solution = Solution();
    target = 12;
    position = {10, 8, 0, 5, 3};
    speed = {2, 4, 1, 1, 3};
    ans = solution.carFleet(target, position, speed);
    cout << ans << '\n';  // 3

    solution = Solution();
    target = 10;
    position = {3};
    speed = {3};
    ans = solution.carFleet(target, position, speed);
    cout << ans << '\n';  // 1

    solution = Solution();
    target = 100;
    position = {0, 2, 4};
    speed = {4, 2, 1};
    ans = solution.carFleet(target, position, speed);
    cout << ans << '\n';  // 1

    // USED SOLUTION
    solution = Solution();
    target = 10;
    position = {6, 8};
    speed = {3, 2};
    ans = solution.carFleet(target, position, speed);
    cout << ans << '\n';  // 2

    // USED SOLUTION
    solution = Solution();
    target = 10;
    position = {0, 4, 2};
    speed = {2, 1, 3};
    ans = solution.carFleet(target, position, speed);
    cout << ans << '\n';  // 1

    // USED SOLUTION
    solution = Solution();
    target = 10;
    position = {3, 5, 7};
    speed = {3, 2, 1};
    ans = solution.carFleet(target, position, speed);
    cout << ans << '\n';  // 1
}
