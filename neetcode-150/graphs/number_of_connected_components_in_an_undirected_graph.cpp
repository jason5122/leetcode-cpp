/*
e = edges.size()
runtime: O(n+e)
space: O(n)
*/
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // Construct adjacency list. Undirected graph means edges go both ways.
        vector<vector<int>> adj(n, vector<int>{});
        for (const auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        int component_count = 0;
        unordered_set<int> visited;
        for (int node = 0; node < n; node++) {
            if (visited.count(node)) continue;
            else component_count++;

            queue<int> q;
            q.push(node);
            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int neighbor : adj[curr]) {
                    if (!visited.count(neighbor)) {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
        }
        return component_count;
    }
};
