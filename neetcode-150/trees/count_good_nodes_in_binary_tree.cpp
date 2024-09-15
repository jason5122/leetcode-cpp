/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return helper(root, root->val);
    }

private:
    int helper(TreeNode* root, int curr_max) {
        if (!root) return 0;

        int val = root->val;
        bool is_good = val >= curr_max;
        int new_max = max(val, curr_max);
        return helper(root->left, new_max) + helper(root->right, new_max) + is_good;
    }
};
