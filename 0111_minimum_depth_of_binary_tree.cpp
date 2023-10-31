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

// n == # of nodes
// runtime: O(n)
// space: O(n)
int min_depth(TreeNode* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr) return min_depth(root->right) + 1;
    if (root->right == nullptr) return min_depth(root->left) + 1;

    int left_min = min_depth(root->left);
    int right_min = min_depth(root->right);
    return min(left_min, right_min) + 1;
}

// n == # of nodes
// runtime: O(n)
// space: O(n)
int min_depth2(TreeNode* root) {
    if (root == nullptr) return 0;

    queue<TreeNode*> bfs;
    bfs.push(root);
    int depth = 1;
    while (!bfs.empty()) {
        int count = bfs.size();
        for (int i = 0; i < count; i++) {
            TreeNode* node = bfs.front();
            bfs.pop();

            // leaf node
            if (node->left == nullptr && node->right == nullptr) return depth;

            if (node->left != nullptr) bfs.push(node->left);
            if (node->right != nullptr) bfs.push(node->right);
        }

        depth++;
    }
    return depth;
}

int main() {
    TreeNode* root =
        new TreeNode(3, new TreeNode(9),
                     new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    int result = min_depth2(root);  // 2
    cout << result << '\n';

    root = new TreeNode(
        2, nullptr,
        new TreeNode(3, nullptr,
                     new TreeNode(4, nullptr,
                                  new TreeNode(5, nullptr, new TreeNode(6)))));
    result = min_depth2(root);  // 5
    cout << result << '\n';

    // USED SOLUTION
    root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)),
                        new TreeNode(3));
    result = min_depth2(root);  // 2
    cout << result << '\n';
}
