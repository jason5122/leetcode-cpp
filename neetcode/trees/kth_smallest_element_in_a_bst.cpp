/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int k;
    int ans;

    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        helper(root);
        return ans;
    }

private:
    void helper(TreeNode* root) {
        if (root->left) helper(root->left);

        if (k == 1) {
            ans = root->val;
        }
        k--;

        if (root->right) helper(root->right);
    }
};

/*
stack = [5]
visited = []

stack = [3 5]
visited = []

stack = [2 3 5]
visited = []

stack = [1 2 3 5]
visited = []

stack = [2 3 5]
visited = [1]

stack = [3 5]
visited = [1 2]

stack = [4 5]
visited = [1 2 3]

n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        unordered_set<TreeNode*> visited;
        stk.push(root);

        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();

            if (node->left && !visited.count(node->left)) {
                stk.push(node);
                stk.push(node->left);
            } else if (!visited.count(node)) {
                visited.insert(node);

                if (k == 1) {
                    return node->val;
                } else {
                    k--;
                }

                if (node->right) stk.push(node->right);
            }
        }
        return -1;  // Unreachable.
    }
};

/*
USED SOLUTION
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while (true) {
            while (root) {
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();

            if (k-- == 1) return root->val;

            root = root->right;
        }
    }
};
