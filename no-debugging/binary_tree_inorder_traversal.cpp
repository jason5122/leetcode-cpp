/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }

private:
    vector<int> ans;

    void helper(TreeNode* root) {
        if (!root) return;

        helper(root->left);
        ans.push_back(root->val);
        helper(root->right);
    }
};

/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        stack<TreeNode*> stk;
        while (true) {
            while (root) {
                stk.push(root);
                root = root->left;
            }

            if (stk.empty()) return ans;

            root = stk.top();
            stk.pop();
            ans.push_back(root->val);

            root = root->right;
        }
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }

            curr = stk.top();
            stk.pop();
            ans.push_back(curr->val);

            curr = curr->right;
        }
        return ans;
    }
};
