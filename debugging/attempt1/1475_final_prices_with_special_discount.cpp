#include "debugging.h"
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

// n == prices.size()
// runtime: O(2n)
// space: O(n)
vector<int> final_prices(vector<int>& prices) {
    stack<int> mono;              // monotonically increasing
    unordered_map<int, int> map;  // index -> discounted price

    for (int i = 0; i < prices.size(); i++) {
        while (!mono.empty() && prices[i] <= prices[mono.top()]) {
            map[mono.top()] = prices[mono.top()] - prices[i];
            mono.pop();
        }
        mono.push(i);
    }

    while (!mono.empty()) {
        map[mono.top()] = prices[mono.top()];
        mono.pop();
    }

    vector<int> result;
    for (int i = 0; i < prices.size(); i++) {
        result.push_back(map[i]);
    }
    return result;
}

int main() {
    vector<int> prices;
    vector<int> result;

    prices = {8, 4, 6, 2, 3};
    result = final_prices(prices);  // [4,2,4,2,3]
    cout << result << '\n';

    prices = {1, 2, 3, 4, 5};
    result = final_prices(prices);  // [1,2,3,4,5]
    cout << result << '\n';

    prices = {10, 1, 1, 6};
    result = final_prices(prices);  // [9,0,1,6]
    cout << result << '\n';
}
