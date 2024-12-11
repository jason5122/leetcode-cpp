/*
n == nums.size()
runtime: O(n*lg(k))
space: O(k)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> pq;

        for (int n : nums) {
            pq.push(n);
            while (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
