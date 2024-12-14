/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);

        vector<vector<int>> ans;
        int depth = 0;
        while (!q.empty()) {
            ans.emplace_back();

            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();

                ans[depth].push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }
        return ans;
    }
};

/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = maxDepth(root);
        ans = vector<vector<int>>(n, vector<int>{});
        helper(root, 0);
        return ans;
    }

private:
    vector<vector<int>> ans;

    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    void helper(TreeNode* root, int depth) {
        if (!root) return;

        ans[depth].push_back(root->val);
        helper(root->left, depth + 1);
        helper(root->right, depth + 1);
    }
};
