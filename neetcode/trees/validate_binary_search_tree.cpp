/*
USED TEST CASES
[2147483647]
[2,2,2]

n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

public:
    bool helper(TreeNode* root, long low, long high) {
        if (!root) return true;

        int val = root->val;
        if (val <= low || val >= high) return false;

        return helper(root->left, low, val) && helper(root->right, val, high);
    }
};

/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        queue<TreeNode*> q;
        queue<pair<long, long>> limits;
        if (root) {
            q.push(root);
            limits.push({LONG_MIN, LONG_MAX});
        }

        while (!q.empty()) {
            auto node = q.front();
            auto [low, high] = limits.front();
            q.pop();
            limits.pop();

            int val = node->val;
            if (val <= low || val >= high) return false;

            if (node->left) {
                q.push(node->left);
                limits.push({low, val});
            }
            if (node->right) {
                q.push(node->right);
                limits.push({val, high});
            }
        }
        return true;
    }
};
