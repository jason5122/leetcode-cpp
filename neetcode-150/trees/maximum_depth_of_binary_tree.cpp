/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        } else {
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
    }
};

/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        if (root) {
            q.push(root);
            visited.insert(root);
        }

        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left && !visited.count(curr->left)) {
                    q.push(curr->left);
                    visited.insert(curr->left);
                }
                if (curr->right && !visited.count(curr->right)) {
                    q.push(curr->right);
                    visited.insert(curr->right);
                }
            }
            depth++;
        }
        return depth;
    }
};
