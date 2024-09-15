/*
n == # of nodes
runtime: O(n^2)
space: O(n)
*/
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int diameter = maxDepth(root->left) + maxDepth(root->right);
        int left_diameter = diameterOfBinaryTree(root->left);
        int right_diameter = diameterOfBinaryTree(root->right);
        return max({diameter, left_diameter, right_diameter});
    }

private:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int diameter = maxDepth(root->left) + maxDepth(root->right);
        int left_diameter = diameterOfBinaryTree(root->left);
        int right_diameter = diameterOfBinaryTree(root->right);
        return max({diameter, left_diameter, right_diameter});
    }

private:
    unordered_map<TreeNode*, int> memo;

    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        if (memo.count(root)) return memo[root];

        return memo[root] = max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
