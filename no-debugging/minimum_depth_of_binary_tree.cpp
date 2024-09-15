/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        int depth = 0;
        if (root) {
            q.push(root);
            visited.insert(root);
            depth = 1;
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                TreeNode* left = curr->left;
                TreeNode* right = curr->right;

                // Found leaf node.
                if (!left && !right) {
                    return depth;
                }

                if (left && !visited.count(left)) {
                    q.push(left);
                    visited.insert(left);
                }
                if (right && !visited.count(right)) {
                    q.push(right);
                    visited.insert(right);
                }
            }
            depth++;
        }
        return depth;
    }
};

/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if (left && right) {
            return min(minDepth(left), minDepth(right)) + 1;
        } else {
            return minDepth(left ? left : right) + 1;
        }
    }
};
