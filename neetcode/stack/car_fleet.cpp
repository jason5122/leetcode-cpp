/*
target = 10
position = [0, 5]
speed = [3, 2]

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
