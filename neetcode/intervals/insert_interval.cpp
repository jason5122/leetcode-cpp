/*
n == intervals.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& it_new) {
        // Insert.
        auto it = intervals.begin();
        for (; it != intervals.end(); it++) {
            int start = (*it)[0];
            if (start >= it_new[0]) {
                intervals.insert(it, it_new);
                break;
            }
        }
        // Edge case: The above loop did not insert.
        if (it == intervals.end()) {
            intervals.push_back(it_new);
        }

        // Merge.
        vector<vector<int>> ans;

        int curr_start = intervals[0][0];
        int curr_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (curr_end >= start) {
                curr_end = max(end, curr_end);
            } else {
                ans.push_back({curr_start, curr_end});

                curr_start = start;
                curr_end = end;
            }
        }
        ans.push_back({curr_start, curr_end});

        return ans;
    }
};

/*
n == intervals.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& it_new) {
        // Insert (binary search).
        int n = intervals.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            int start = intervals[m][0];
            if (start < it_new[0]) {
                l = m + 1;
            } else if (start > it_new[0]) {
                r = m - 1;
            } else {
                l = m;
                break;
            }
        }
        intervals.insert(intervals.begin() + l, it_new);

        // Merge.
        vector<vector<int>> ans;

        int curr_start = intervals[0][0];
        int curr_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (curr_end >= start) {
                curr_end = max(end, curr_end);
            } else {
                ans.push_back({curr_start, curr_end});

                curr_start = start;
                curr_end = end;
            }
        }
        ans.push_back({curr_start, curr_end});

        return ans;
    }
};
