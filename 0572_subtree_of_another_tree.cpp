#include <iostream>
#include <queue>
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

bool is_equal(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    if (root1->val != root2->val) return false;

    return is_equal(root1->left, root2->left) &&
           is_equal(root1->right, root2->right);
}

// m == # of nodes in root
// n == # of nodes in sub_root
// runtime: O(m*n)
// space: O(m+n)
bool is_subtree(TreeNode* root, TreeNode* sub_root) {
    queue<TreeNode*> bfs;
    bfs.push(root);

    while (!bfs.empty()) {
        TreeNode* node = bfs.front();
        bfs.pop();
        if (is_equal(node, sub_root)) return true;

        if (node->left) bfs.push(node->left);
        if (node->right) bfs.push(node->right);
    }
    return false;
}

// m == # of nodes in root
// n == # of nodes in sub_root
// runtime: O(m*n)
// space: O(m+n)
bool is_subtree2(TreeNode* root, TreeNode* sub_root) {
    if (!root) return sub_root == nullptr;

    bool curr = is_equal(root, sub_root);
    bool left = is_subtree2(root->left, sub_root);
    bool right = is_subtree2(root->right, sub_root);
    return curr || left || right;
}

int main() {
    TreeNode* root = new TreeNode(
        3, new TreeNode(4, new TreeNode(1), new TreeNode(2)), new TreeNode(5));
    TreeNode* sub_root = new TreeNode(4, new TreeNode(1), new TreeNode(2));
    bool result = is_subtree2(root, sub_root);  // true
    cout << result << '\n';

    root =
        new TreeNode(3,
                     new TreeNode(4, new TreeNode(1),
                                  new TreeNode(2, new TreeNode(0), nullptr)),
                     new TreeNode(5));
    result = is_subtree2(root, sub_root);  // false
    cout << result << '\n';
}
