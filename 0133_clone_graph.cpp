#include "debugging.h"
#include "leetcode.h"
using namespace std;

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

void PrintAdjacencyList(Node* node) {
    cerr << format("{}: ", node->val);
    for (const auto& n : node->neighbors) {
        cerr << format("{} ({:#x}) ", n->val, reinterpret_cast<intptr_t>(n));
    }
    cerr << '\n';
}

void PrintAdjacencyListOfGraph(Node* head) {
    queue<Node*> q;
    unordered_set<int> visited;

    q.push(head);
    visited.insert(head->val);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        PrintAdjacencyList(node);
        for (const auto& n : node->neighbors) {
            if (!visited.count(n->val)) {
                q.push(n);
                visited.insert(n->val);
            }
        }
    }
}

/*
USED SOLUTION
v == # of vertices
e == # of edges
runtime: O(v+e)
space: O(v)
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

int main() {
    Solution soln;
    Node* node;
    Node* ans;

    soln = Solution();
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};
    node = n1;
    ans = soln.cloneGraph(node);
    // PrintAdjacencyListOfGraph(ans);

    Node* a1 = ans;
    Node* a2 = ans->neighbors[0];
    Node* a4 = ans->neighbors[1];
    Node* a3 = a2->neighbors[1];
    cerr << format("{} ({:#x})\n", a1->val, reinterpret_cast<intptr_t>(a1));
    cerr << format("{} ({:#x})\n", a2->val, reinterpret_cast<intptr_t>(a2));
    cerr << format("{} ({:#x})\n", a3->val, reinterpret_cast<intptr_t>(a3));
    cerr << format("{} ({:#x})\n", a4->val, reinterpret_cast<intptr_t>(a4));
    PrintAdjacencyList(a1);
    PrintAdjacencyList(a2);
    PrintAdjacencyList(a3);
    PrintAdjacencyList(a4);
}
