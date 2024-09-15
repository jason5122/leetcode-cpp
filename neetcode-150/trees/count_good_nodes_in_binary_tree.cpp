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

/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        int ans = 0;
        while (!q.empty()) {
            auto [node, curr_max] = q.front();
            q.pop();

            int val = node->val;
            if (val >= curr_max) {
                ans++;
            }

            int new_max = max(val, curr_max);
            if (node->left) {
                q.push({node->left, new_max});
            }
            if (node->right) {
                q.push({node->right, new_max});
            }
        }
        return ans;
    }
};
