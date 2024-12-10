/*
n == intervals.size()
runtime: O(n*lg(n))
space: O(1)
*/
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        for (int i = 1; i < intervals.size(); i++) {
            int prev_end = intervals[i - 1][1];
            int start = intervals[i][0];
            if (prev_end > start) {
                return false;
            }
        }
        return true;
    }
};
