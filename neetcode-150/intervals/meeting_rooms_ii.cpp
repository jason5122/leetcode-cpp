/*
USED TEST CASE
intervals = [[9,10],[4,9],[4,17]]

n == intervals.size()
runtime: O(n*lg(n))
space: O(n)
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // Sort by start time, ascending.
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<>> rooms;
        rooms.push(intervals[0][1]);

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // Reuse existing room.
            if (!rooms.empty() && rooms.top() <= start) {
                rooms.pop();
            }
            rooms.push(end);
        }
        return rooms.size();
    }
};
