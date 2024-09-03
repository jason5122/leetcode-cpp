/*
TIME LIMIT EXCEEDED
n == target - startValue
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        queue<int> q;
        unordered_set<int> visited;
        q.push(startValue);
        visited.insert(startValue);

        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int n = q.front();
                q.pop();

                if (n == target) {
                    return depth;
                }

                if (n < target && !visited.count(n * 2)) {
                    q.push(n * 2);
                    visited.insert(n * 2);
                }
                if (!visited.count(n - 1)) {
                    q.push(n - 1);
                    visited.insert(n - 1);
                }
            }
            depth++;
        }
        return depth;
    }
};

/*
USED SOLUTION
n == target - startValue
runtime: O(lg(n))
space: O(1)
*/
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while (target > startValue) {
            if (target % 2 == 0) {
                target /= 2;
            } else {
                target += 1;
            }
            ans++;
        }
        return ans + startValue - target;
    }
};
