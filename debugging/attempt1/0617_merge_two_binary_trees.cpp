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

void print_tree(TreeNode* root, int indent) {
    if (root == nullptr) {
        cout << '\n';
        return;
    }

    cout << root->val << '\n';

    if (root->left == nullptr && root->right == nullptr) return;

    for (int i = 0; i < indent; i++) cout << ' ';
    cout << "└ ";
    print_tree(root->left, indent + 2);

    for (int i = 0; i < indent; i++) cout << ' ';
    cout << "└ ";
    print_tree(root->right, indent + 2);
}

void print_tree(TreeNode* root) { print_tree(root, 0); }

// n == total # of nodes in root1 and root2
// runtime: O(n)
// space: O(n)
TreeNode* merge_trees(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr) return root2;
    if (root2 == nullptr) return root1;

    int val = root1->val + root2->val;
    TreeNode* right = merge_trees(root1->right, root2->right);
    TreeNode* left = merge_trees(root1->left, root2->left);

    TreeNode* root = new TreeNode(val, left, right);
    return root;
}

// USED SOLUTION
// n == total # of nodes in root1 and root2
// runtime: O(n)
// space: O(n)
TreeNode* merge_trees2(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr) return root2;
    if (root2 == nullptr) return root1;

    stack<pair<TreeNode*, TreeNode*>> dfs;
    dfs.push({root1, root2});

    while (!dfs.empty()) {
        TreeNode* node1;
        TreeNode* node2;
        tie(node1, node2) = dfs.top();
        dfs.pop();

        node1->val += node2->val;

        if (!node1->left && node2->left) {
            node1->left = node2->left;
        } else if (node1->left && node2->left) {
            dfs.push({node1->left, node2->left});
        }

        if (!node1->right && node2->right) {
            node1->right = node2->right;
        } else if (node1->right && node2->right) {
            dfs.push({node1->right, node2->right});
        }
    }
    return root1;
}

int main() {
    TreeNode* root1 = new TreeNode(
        1, new TreeNode(3, new TreeNode(5), nullptr), new TreeNode(2));
    TreeNode* root2 =
        new TreeNode(2, new TreeNode(1, nullptr, new TreeNode(4)),
                     new TreeNode(3, nullptr, new TreeNode(7)));
    TreeNode* result = merge_trees2(root1, root2);  // [3,4,5,5,4,null,7]
    print_tree(result);

    root1 = new TreeNode(1);
    root2 = new TreeNode(1, new TreeNode(2), nullptr);
    result = merge_trees2(root1, root2);  // [2,2]
    print_tree(result);
}
