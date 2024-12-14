/*
n == nums.size()
runtime: O(n*lg(n))
space: O(k)
*/
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k{k} {
        for (int n : nums) {
            add(n);
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }

private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
};
