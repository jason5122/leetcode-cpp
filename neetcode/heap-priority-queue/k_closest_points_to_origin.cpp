/*
n == points.size()
runtime: O(n*lg(k))
space: O(k)
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [this](auto& p1, auto& p2) { return distance(p1) < distance(p2); };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

        for (auto& p : points) {
            pq.push(p);
            while (pq.size() > k) pq.pop();
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }

private:
    double distance(vector<int>& p) {
        return sqrt(pow(p[0], 2) + pow(p[1], 2));
    }
};
