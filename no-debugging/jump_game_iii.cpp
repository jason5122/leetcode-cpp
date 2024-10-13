/*
n == arr.size()
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (arr[i] == 0) {
                return true;
            }

            int add = i + arr[i];
            int sub = i - arr[i];
            if (add < n && !visited[add]) {
                q.push(add);
                visited[add] = true;
            }
            if (sub >= 0 && !visited[sub]) {
                q.push(sub);
                visited[sub] = true;
            }
        }
        return false;
    }
};
