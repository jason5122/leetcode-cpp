class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

private:
    bool helper(TreeNode* root, long low, long high) {
        if (!root) return true;
        if (root->val <= low || root->val >= high) return false;

        return helper(root->left, low, root->val) && helper(root->right, root->val, high);
    }
};
