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

// n == # of nodes
// runtime: O(n)
// space: O(n)
TreeNode* invert_tree(TreeNode* root) {
    if (!root) return root;

    TreeNode* temp = invert_tree(root->left);
    root->left = invert_tree(root->right);
    root->right = temp;

    return root;
}

// n == # of nodes
// runtime: O(n)
// space: O(n)
TreeNode* invert_tree2(TreeNode* root) {
    if (!root) return root;

    queue<TreeNode*> bfs;
    bfs.push(root);
    while (!bfs.empty()) {
        TreeNode* node = bfs.front();
        bfs.pop();

        // swap
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;

        if (node->left) bfs.push(node->left);
        if (node->right) bfs.push(node->right);
    }
    return root;
}

int main() {
    TreeNode* root =
        new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)),
                     new TreeNode(7, new TreeNode(6), new TreeNode(9)));
    TreeNode* result = invert_tree2(root);  // [4,7,2,9,6,3,1]
    print_tree(result);

    root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    result = invert_tree2(root);  // [2,3,1]
    print_tree(result);

    root = nullptr;
    result = invert_tree(root);  // []
    cout << (result == nullptr) << '\n';

    root = new TreeNode(1, new TreeNode(2), nullptr);
    result = invert_tree2(root);  // [1,null,2]
    print_tree(result);
}
