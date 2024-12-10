/*
E == edges.size()
runtime: O(V+E)
space: O(V+E)

The adjacency list takes O(E) space.
The indegree list takes O(V) space.
The queue takes at most O(V) space.
*/
class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        // Create adjacency list.
        vector<vector<int>> adj(V);
        for (auto& p : edges) {
            adj[p[1]].emplace_back(p[0]);
        }

        // Calculate indegrees.
        vector<int> indegree(V);
        for (auto& p : edges) {
            indegree[p[0]]++;
        }

        // Kahn's algorithm.
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int removed = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            removed++;

            for (int child : adj[node]) {
                indegree[child]--;

                if (indegree[child] == 0) {
                    q.push(child);
                }
            }
        }
        return removed == V;
    }
};
