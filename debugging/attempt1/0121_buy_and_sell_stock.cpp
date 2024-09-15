#include <iostream>
#include <vector>
using namespace std;

// runtime: O(n)
// space: O(1)
int max_profit(vector<int>& prices) {
    int max = 0;

    int curr = prices[0];
    for (int price : prices) {
        if (price - curr > max) {
            max = price - curr;
        }

        if (price < curr) {
            curr = price;
        }
    }

    return max;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = max_profit(prices);
    cout << result << '\n';  // 5

    prices = {7, 6, 4, 3, 1};
    result = max_profit(prices);
    cout << result << '\n';  // 0
}
