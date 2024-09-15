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
bool has_path_sum(TreeNode* root, int target_sum) {
    if (root == nullptr) return false;

    int new_sum = target_sum - root->val;

    // leaf node
    if (root->left == nullptr && root->right == nullptr) {
        return new_sum == 0;
    }

    bool is_left = has_path_sum(root->left, new_sum);
    bool is_right = has_path_sum(root->right, new_sum);
    return is_left || is_right;
}

// USED SOLUTION
// n == # of nodes
// runtime: O(n)
// space: O(n)
bool has_path_sum2(TreeNode* root, int target_sum) {
    if (root == nullptr) return false;

    stack<pair<TreeNode*, int>> dfs;
    dfs.push({root, target_sum});

    while (!dfs.empty()) {
        TreeNode* node;
        int path_sum;
        tie(node, path_sum) = dfs.top();
        dfs.pop();

        int new_sum = path_sum - node->val;

        // leaf node
        if (node->left == nullptr && node->right == nullptr) {
            if (new_sum == 0) return true;
        }

        if (node->left != nullptr) dfs.push({node->left, new_sum});
        if (node->right != nullptr) dfs.push({node->right, new_sum});
    }
    return false;
}

int main() {
    TreeNode* root = new TreeNode(
        5,
        new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)),
                     nullptr),
        new TreeNode(8, new TreeNode(13),
                     new TreeNode(4, nullptr, new TreeNode(1))));
    int target_sum = 22;
    bool result = has_path_sum2(root, target_sum);  // true
    cout << result << '\n';

    root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    target_sum = 5;
    result = has_path_sum2(root, target_sum);  // false
    cout << result << '\n';

    root = nullptr;
    target_sum = 0;
    result = has_path_sum2(root, target_sum);  // false
    cout << result << '\n';
}
