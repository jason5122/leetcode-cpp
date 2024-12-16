/*
n == nums.size()
runtime: O(n*lg(k))
space: O(n+k)

frequency map takes O(n) space
heap takes O(k) space
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for (int a : nums) freqs[a]++;

        auto comp = [&](int a1, int a2) { return freqs[a1] > freqs[a2]; };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);

        for (auto [a, freq] : freqs) {
            pq.push(a);
            if (pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
