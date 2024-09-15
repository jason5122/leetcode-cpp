/*
m == # of nodes in root
n == # of nodes in subRoot
runtime: O(m*n)
space: O(m+n)
*/
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot) return !root && !subRoot;

        return equal(root, subRoot) || isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }

private:
    bool equal(TreeNode* r1, TreeNode* r2) {
        if (!r1 || !r2) return !r1 && !r2;
        if (r1->val != r2->val) return false;

        return equal(r1->left, r2->left) && equal(r1->right, r2->right);
    }
};
