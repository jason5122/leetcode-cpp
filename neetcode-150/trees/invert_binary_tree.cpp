/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;

        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};
