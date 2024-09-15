#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

queue<TreeNode*> get_path(TreeNode* root, TreeNode* target) {
    stack<TreeNode*> dfs;
    dfs.push(root);

    queue<TreeNode*> path;
    while (!dfs.empty()) {
        TreeNode* node = dfs.top();
        dfs.pop();
        path.push(node);

        if (target->val < node->val) {
            dfs.push(node->left);
        } else if (target->val > node->val) {
            dfs.push(node->right);
        } else {
            return path;
        }
    }
    return path;  // not found
}

// n == # of nodes
// runtime: O(n)
// space: O(n)
TreeNode* lowest_common_ancestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    queue<TreeNode*> path_p = get_path(root, p);
    queue<TreeNode*> path_q = get_path(root, q);

    TreeNode* lca;
    while (path_p.front() == path_q.front()) {
        lca = path_p.front();
        path_p.pop();
        path_q.pop();
    }

    return lca;
}

// n == # of nodes
// runtime: O(n)
// space: O(n)
TreeNode* lowest_common_ancestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == p || root == q) return root;

    if (p->val < root->val && q->val < root->val) {
        return lowest_common_ancestor2(root->left, p, q);
    } else if (p->val > root->val && q->val > root->val) {
        return lowest_common_ancestor2(root->right, p, q);
    } else {
        return root;
    }
}

// USED SOLUTION
// n == # of nodes
// runtime: O(n)
// space: O(1)
TreeNode* lowest_common_ancestor3(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* curr = root;
    while (curr) {
        if (curr == p || curr == q) return curr;

        if (p->val < curr->val && q->val < curr->val) {
            curr = curr->left;
        } else if (p->val > curr->val && q->val > curr->val) {
            curr = curr->right;
        } else {
            return curr;
        }
    }
    return curr;
}

int main() {
    TreeNode* p = new TreeNode(
        2, new TreeNode(0), new TreeNode(4, new TreeNode(3), new TreeNode(5)));
    TreeNode* q = new TreeNode(8, new TreeNode(7), new TreeNode(9));
    TreeNode* root = new TreeNode(6, p, q);
    TreeNode* result = lowest_common_ancestor3(root, p, q);  // 6
    cout << (result == root) << '\n';

    q = new TreeNode(4, new TreeNode(3), new TreeNode(5));
    p = new TreeNode(2, new TreeNode(0), q);
    root =
        new TreeNode(6, p, new TreeNode(8, new TreeNode(7), new TreeNode(9)));
    result = lowest_common_ancestor3(root, p, q);  // 2
    cout << (result == p) << '\n';
}
