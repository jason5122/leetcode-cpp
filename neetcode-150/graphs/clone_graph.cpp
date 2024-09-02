/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

/*
USED SOLUTION
v == # of vertices
e == # of edges
runtime: O(v+e)
space: O(v)

Don't always create a new node. Use a map to ensure originals and clones are 1:1.
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        queue<Node*> q;
        unordered_set<int> visited;
        unordered_map<Node*, Node*> clone_map;  // original -> clone

        q.push(node);
        visited.insert(node->val);
        clone_map[node] = new Node(node->val);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            for (const auto& n : curr->neighbors) {
                if (!visited.count(n->val)) {
                    q.push(n);
                    visited.insert(n->val);
                    clone_map[n] = new Node(n->val);
                }

                clone_map[curr]->neighbors.push_back(clone_map[n]);
            }
        }
        return clone_map[node];
    }
};
