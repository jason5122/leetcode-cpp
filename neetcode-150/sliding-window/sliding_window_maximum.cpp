/*
1 5 -1 -3 2
k = 2

pq: 5 1
deleted: {}

pq: 5 1 -1
deleted: { 1: 1 }

pq: 5 1 -1 -3
deleted: { 1: 1, 5: 1 }
->
pq: -1 -3
deleted: { 1: 0, 5: 0 }

pq: 2 -1 -3
deleted: { 1: 0, 5: 0, -3: 1 }

KINDA USED SOLUTION (ACCIDENTALLY STUMBLED ON STACKOVERFLOW IDEA)
n == nums.size()
runtime: O(2n*lg(n))
space: O(2n)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<int> pq;
        unordered_map<int, int> deleted;

        for (int i = 0; i < k; i++) pq.push(nums[i]);
        ans.push_back(pq.top());

        for (int i = k; i < nums.size(); i++) {
            pq.push(nums[i]);
            deleted[nums[i - k]]++;

            while (deleted[pq.top()] > 0) {
                deleted[pq.top()]--;
                pq.pop();
            }

            ans.push_back(pq.top());
        }
        return ans;
    }
};

/*
1 5 -1 -3 2
k = 2

dq: 5
dq: 5 -1
dq: -1 -3
dq: 2

USED SOLUTION
n == nums.size()
runtime: O(2n)
space: O(k)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);

        for (int i = k; i < nums.size(); i++) {
            if (dq.front() == i - k) dq.pop_front();  // remove b/c out of window

            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
