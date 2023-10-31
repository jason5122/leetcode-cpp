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

// n == # of nodes
// runtime: O(n)
// space: O(n)
int max_depth(TreeNode* root) {
    if (root == nullptr) return 0;

    int left = max_depth(root->left);
    int right = max_depth(root->right);
    return max(left, right) + 1;
}

// n == # of nodes
// runtime: O(n)
// space: O(n)
int max_depth2(TreeNode* root) {
    if (root == nullptr) return 0;

    stack<pair<TreeNode*, int>> dfs;
    dfs.push({root, 0});

    int max_depth = 0;
    while (!dfs.empty()) {
        TreeNode* node;
        int depth;
        tie(node, depth) = dfs.top();
        dfs.pop();

        int new_depth = depth + 1;

        // leaf node
        if (node->left == nullptr && node->right == nullptr) {
            max_depth = max(new_depth, max_depth);
        }

        if (node->left != nullptr) dfs.push({node->left, new_depth});
        if (node->right != nullptr) dfs.push({node->right, new_depth});
    }
    return max_depth;
}

int main() {
    TreeNode* root =
        new TreeNode(3, new TreeNode(9),
                     new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    int result = max_depth2(root);  // 3
    cout << result << '\n';

    root = new TreeNode(1, nullptr, new TreeNode(2));
    result = max_depth2(root);  // 2
    cout << result << '\n';
}
