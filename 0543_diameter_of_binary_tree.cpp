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

int max_depth(TreeNode* root) {
    if (root == nullptr) return 0;

    int left = max_depth(root->left);
    int right = max_depth(root->right);
    return max(left, right) + 1;
}

// n == # of nodes
// runtime: O(n^2)
// space: O(n)
int diameter_of_binary_tree(TreeNode* root) {
    if (root == nullptr) return 0;

    stack<TreeNode*> dfs;
    dfs.push(root);

    int diameter = 0;
    while (!dfs.empty()) {
        TreeNode* node = dfs.top();
        dfs.pop();

        int left = max_depth(node->left);
        int right = max_depth(node->right);
        diameter = max(diameter, left + right);

        if (node->left != nullptr) dfs.push(node->left);
        if (node->right != nullptr) dfs.push(node->right);
    }
    return diameter;
}

int diameter = 0;
int max_depth2(TreeNode* root) {
    if (root == nullptr) return 0;

    int left = max_depth(root->left);
    int right = max_depth(root->right);

    diameter = max(diameter, left + right);

    return max(left, right) + 1;
}

// USED SOLUTION
// n == # of nodes
// runtime: O(n)
// space: O(n)
int diameter_of_binary_tree2(TreeNode* root) {
    diameter = 0;
    max_depth2(root);
    return diameter;
}

int main() {
    TreeNode* root = new TreeNode(
        1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    int result = diameter_of_binary_tree2(root);  // 3
    cout << result << '\n';

    root = new TreeNode(1, new TreeNode(2), nullptr);
    result = diameter_of_binary_tree2(root);  // 1
    cout << result << '\n';
}
