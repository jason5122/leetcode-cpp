class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort by start time, ascending.
        sort(intervals.begin(), intervals.end());

        int ans = 0;

        int prev_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // Overlap found.
            if (prev_end > start) {
                ans++;
                prev_end = min(end, prev_end);
            } else {
                prev_end = end;
            }
        }
        return ans;
    }
};
