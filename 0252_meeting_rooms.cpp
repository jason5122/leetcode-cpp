#include <iostream>
#include <vector>
using namespace std;

// n == intervals.size()
// runtime: O(n)
// space: O(1)
bool can_attend_meetings(vector<vector<int>>& intervals) {
    auto compare = [](vector<int> i1, vector<int> i2) {
        return i1[0] < i2[0];
    };
    sort(intervals.begin(), intervals.end(), compare);

    for (int i = 1; i < intervals.size(); i++) {
        int end = intervals[i - 1][1];
        int start = intervals[i][0];
        if (end > start) return false;
    }

    return true;
}

int main() {
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    bool result = can_attend_meetings(intervals);
    cout << result << '\n';  // false

    intervals = {{7, 10}, {2, 4}};
    result = can_attend_meetings(intervals);
    cout << result << '\n';  // true
}
