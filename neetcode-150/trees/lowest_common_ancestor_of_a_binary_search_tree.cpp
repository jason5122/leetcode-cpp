/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
        populateAncestorMap(root, n1, is_ancestor_of_n1);
        populateAncestorMap(root, n2, is_ancestor_of_n2);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(root);
        visited.insert(root);

        TreeNode* ans = root;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            if (is_ancestor_of_n1[node] && is_ancestor_of_n2[node]) {
                ans = node;
            }

            if (is_ancestor_of_n1[node->left] && is_ancestor_of_n2[node->left]) {
                q.push(node->left);
                visited.insert(node->left);
            }
            if (is_ancestor_of_n1[node->right] && is_ancestor_of_n2[node->right]) {
                q.push(node->right);
                visited.insert(node->right);
            }
        }
        return ans;
    }

private:
    using Memo = unordered_map<TreeNode*, bool>;
    Memo is_ancestor_of_n1;
    Memo is_ancestor_of_n2;

    bool populateAncestorMap(TreeNode* root, TreeNode* node, Memo& memo) {
        if (!root) return false;

        bool in_left = populateAncestorMap(root->left, node, memo);
        bool in_right = populateAncestorMap(root->right, node, memo);
        return memo[root] = root == node || in_left || in_right;
    }
};
