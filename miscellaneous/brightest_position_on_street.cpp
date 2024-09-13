// https://leetcode.ca/2021-10-05-2021-Brightest-Position-on-Street/

/*
WRONG ANSWER

lights = [[8,2],[4,5],[3,6],[6,2],[-1,3],[4,2],[-3,2]]
ranges = [[6,10], [-1,9], [-3,9], [4,8], [-4,2], [2,6], [-5,-1]]
sorted = [[-5,-1], [-4,2], [-3,9], [-1,9], [2,6], [4,8], [6,10]]
*/
class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        vector<pair<int, int>> ranges;
        for (const auto& light : lights) {
            int p = light[0];
            int r = light[1];
            ranges.emplace_back(p - r, p + r);
        }
        sort(ranges.begin(), ranges.end());

        int ans = ranges[0].first;
        int max_count = 1;

        stack<pair<int, int>> stk;
        stk.push(ranges[0]);
        for (const auto& range : ranges) {
            while (!stk.empty() && range.first > stk.top().second) {
                stk.pop();
            }

            if (stk.empty()) {
                stk.push(range);
            } else {
                int max_left = max(stk.top().first, range.first);
                int min_right = min(stk.top().second, range.second);
                stk.push({max_left, min_right});
            }

            if (stk.size() > max_count) {
                max_count = stk.size();
                ans = stk.top().first;
            }
        }
        return ans;
    }
};

/*
USED TEST CASE
lights = [[8,2],[4,5],[3,6],[6,2],[-1,3],[4,2],[-3,2]]
ranges = [[6,10], [-1,9], [-3,9], [4,8], [-4,2], [2,6], [-5,-1]]
sorted = [[-5,-1], [-4,2], [-3,9], [-1,9], [2,6], [4,8], [6,10]]

[-5,-1], [-4,2], [-3,9], [-1,9] OVERLAP
[-3,9], [-1,9], [2,6], [4,8], [6,10] OVERLAP, ans = 6

n == lights.size()
runtime: O(n*lg(n))
space: O(n)
*/
class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        vector<pair<int, int>> ranges;
        for (const auto& light : lights) {
            int p = light[0];
            int r = light[1];
            ranges.emplace_back(p - r, p + r);
        }
        sort(ranges.begin(), ranges.end());

        int ans = ranges[0].first;
        int max_count = 1;

        // Priority queue stores right ranges, ascending.
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(ranges[0].second);

        for (int i = 1; i < ranges.size(); i++) {
            while (!pq.empty() && ranges[i].first > pq.top()) {
                pq.pop();
            }
            pq.push(ranges[i].second);

            if (pq.size() > max_count) {
                max_count = pq.size();
                ans = ranges[i].first;
            }
        }
        return ans;
    }
};
