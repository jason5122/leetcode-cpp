/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int left_depth = maxDepth(left);
        int right_depth = maxDepth(right);
        return abs(left_depth - right_depth) <= 1 && isBalanced(left) && isBalanced(right);
    }

private:
    unordered_map<TreeNode*, int> memo;

    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        if (memo.count(root)) return memo[root];

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
