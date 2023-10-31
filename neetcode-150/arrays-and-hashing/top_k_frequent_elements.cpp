/*
n == nums.size()
runtime: O(n*lg n)
space: O(n)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int n : nums) counts[n]++;

        vector<pair<int, int>> entries(counts.begin(), counts.end());
        sort(entries.begin(), entries.end(),
             [](const auto& entry1, const auto& entry2) { return entry1.second > entry2.second; });

        vector<int> ans;
        for (const auto& [n, count] : entries) {
            ans.push_back(n);
            k--;
            if (k == 0) break;
        }
        return ans;
    }
};

/*
USED SOLUTION
n == nums.size()
runtime: O(n*lg n)
space: O(n)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int n : nums) counts[n]++;

        auto cmp = [](const auto& pair1, const auto& pair2) {
            return pair1.second < pair2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(counts.begin(),
                                                                                 counts.end());

        vector<int> ans;
        while (k--) {
            auto [n, count] = pq.top();
            pq.pop();
            ans.push_back(n);
        }
        return ans;
    }
};

/*
USED SOLUTION
n == nums.size()
runtime: O(n*lg k)
space: O(n)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int n : nums) counts[n]++;

        auto cmp = [&counts](int n1, int n2) { return counts[n1] > counts[n2]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (const auto& [n, count] : counts) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while (k--) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
