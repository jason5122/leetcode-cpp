/*
n == intervals.size()
runtime: O(n*lg(n))
space: O(1)
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort by start time, ascending.
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        int curr_start = intervals[0][0];
        int curr_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // Extend interval.
            if (curr_end >= start) {
                curr_end = max(end, curr_end);
            }
            // Create new interval.
            else {
                ans.push_back({curr_start, curr_end});
                curr_start = start;
                curr_end = end;
            }
        }
        ans.push_back({curr_start, curr_end});

        return ans;
    }
};
