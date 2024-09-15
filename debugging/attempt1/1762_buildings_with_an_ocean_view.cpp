#include "debugging.h"
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

// n == heights.size()
// runtime: O(2n)
// space: O(n)
vector<int> find_buildings(vector<int>& heights) {
    deque<int> mono;  // monotonically increasing

    for (int i = 0; i < heights.size(); i++) {
        while (!mono.empty() && heights[i] >= heights[mono.back()]) {
            mono.pop_back();
        }
        mono.push_back(i);
    }

    vector<int> result;
    while (!mono.empty()) {
        result.push_back(mono.front());
        mono.pop_front();
    }
    return result;
}

// USED SOLUTION
vector<int> find_buildings2(vector<int>& heights) {
    vector<int> result;

    for (int i = 0; i < heights.size(); i++) {
        while (!result.empty() && heights[result.back()] <= heights[i]) {
            result.pop_back();
        }
        result.push_back(i);
    }
    return result;
}

int main() {
    vector<int> heights;
    vector<int> result;

    heights = {4, 2, 3, 1};
    result = find_buildings2(heights);
    cout << result << '\n';  // [0,2,3]

    heights = {4, 3, 2, 1};
    result = find_buildings2(heights);
    cout << result << '\n';  // [0,1,2,3]

    heights = {1, 3, 2, 4};
    result = find_buildings2(heights);
    cout << result << '\n';  // [3]
}
