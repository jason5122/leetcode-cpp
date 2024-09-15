#include <iostream>
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

// n == total # of nodes in p and q
// runtime: O(n)
// space: O(n)
bool is_same_tree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;

    stack<TreeNode*> dfs_p;
    stack<TreeNode*> dfs_q;
    dfs_p.push(p);
    dfs_q.push(q);

    while (!dfs_p.empty() && !dfs_q.empty()) {
        TreeNode* node_p = dfs_p.top();
        TreeNode* node_q = dfs_q.top();
        dfs_p.pop();
        dfs_q.pop();

        if (node_p->val != node_q->val) return false;

        if (node_p->left != nullptr && node_q->left != nullptr) {
            dfs_p.push(node_p->left);
            dfs_q.push(node_q->left);
        } else if (node_p->left != nullptr || node_q->left != nullptr) {
            return false;
        }

        if (node_p->right != nullptr && node_q->right != nullptr) {
            dfs_p.push(node_p->right);
            dfs_q.push(node_q->right);
        } else if (node_p->right != nullptr || node_q->right != nullptr) {
            return false;
        }
    }
    return dfs_p.empty() && dfs_q.empty();
}

bool is_same_tree2(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;

    if (p->val != q->val) return false;
    bool same_left = is_same_tree2(p->left, q->left);
    bool same_right = is_same_tree2(p->right, q->right);
    return same_left && same_right;
}

int main() {
    TreeNode* p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    bool result = is_same_tree2(p, q);  // true
    cout << result << '\n';

    p = new TreeNode(1, new TreeNode(2), nullptr);
    q = new TreeNode(1, nullptr, new TreeNode(2));
    result = is_same_tree2(p, q);  // false
    cout << result << '\n';

    p = new TreeNode(1, new TreeNode(2), new TreeNode(1));
    q = new TreeNode(1, new TreeNode(1), new TreeNode(2));
    result = is_same_tree2(p, q);  // false
    cout << result << '\n';
}
