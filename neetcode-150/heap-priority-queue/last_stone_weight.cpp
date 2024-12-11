/*
n == stones.size()
runtime: O(n*lg(n))
space: O(n)
*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() >= 2) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if (y > x) {
                pq.push(y - x);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
