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

/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    TreeNode* ans = nullptr;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q, INT_MIN, INT_MAX);
        return ans;
    }

private:
    void helper(TreeNode* root, TreeNode* p, TreeNode* q, int max_left, int min_right) {
        if (!root) return;
        if (p->val < max_left || p->val > min_right) return;
        if (q->val < max_left || q->val > min_right) return;

        if (root == p || root == q) {
            ans = root;
            return;
        }

        ans = root;
        helper(root->left, p, q, max_left, root->val);
        helper(root->right, p, q, root->val, min_right);
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val = root->val;
        int p_val = p->val;
        int q_val = q->val;

        if (p_val < val && q_val < val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p_val > val && q_val > val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();

            int val = node->val;
            int p_val = p->val;
            int q_val = q->val;

            if (p_val < val && q_val < val) {
                stk.push(node->left);
            } else if (p_val > val && q_val > val) {
                stk.push(node->right);
            } else {
                return node;
            }
        }
        return root;  // Unreachable.
    }
};

/*
USED SOLUTION
n == # of nodes
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        while (curr) {
            int val = curr->val;
            int p_val = p->val;
            int q_val = q->val;

            if (p_val < val && q_val < val) {
                curr = curr->left;
            } else if (p_val > val && q_val > val) {
                curr = curr->right;
            } else {
                return curr;
            }
        }
        return root;  // Unreachable.
    }
};
