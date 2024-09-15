/*
m == # of nodes in p
n == # of nodes in q
runtime: O(min(m,n))
space: O(min(m,n))
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            return !p && !q;
        }

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        unordered_set<TreeNode*> visited1;
        unordered_set<TreeNode*> visited2;
        q1.push(p);
        q2.push(q);
        visited1.insert(p);
        visited2.insert(q);

        while (!q1.empty() && !q2.empty()) {
            auto node1 = q1.front();
            auto node2 = q2.front();
            q1.pop();
            q2.pop();

            if (node1->val != node2->val) {
                return false;
            }
            if ((node1->left == nullptr) != (node2->left == nullptr)) {
                return false;
            }
            if ((node1->right == nullptr) != (node2->right == nullptr)) {
                return false;
            }

            if (node1->left && node2->left) {
                q1.push(node1->left);
                q2.push(node2->left);
                visited1.insert(node1);
                visited2.insert(node2);
            }
            if (node1->right && node2->right) {
                q1.push(node1->right);
                q2.push(node2->right);
                visited1.insert(node1);
                visited2.insert(node2);
            }
        }
        return q1.empty() && q2.empty();
    }
};

/*
m == # of nodes in p
n == # of nodes in q
runtime: O(min(m,n))
space: O(min(m,n))
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return !p && !q;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

/*
USED PARTIAL SOLUTION
m == # of nodes in p
n == # of nodes in q
runtime: O(min(m,n))
space: O(min(m,n))
*/
class Solution {
public:
    bool isSameTree(TreeNode* r1, TreeNode* r2) {
        if (!r1 || !r2) return !r1 && !r2;

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(r1);
        q.push(r2);
        visited.insert(r1);
        visited.insert(r2);

        while (!q.empty()) {
            auto node1 = q.front();
            q.pop();
            auto node2 = q.front();
            q.pop();

            if (node1->val != node2->val) return false;
            if ((node1->left == nullptr) != (node2->left == nullptr)) return false;
            if ((node1->right == nullptr) != (node2->right == nullptr)) return false;

            if (node1->left && node2->left) {
                q.push(node1->left);
                q.push(node2->left);
                visited.insert(node1);
                visited.insert(node2);
            }
            if (node1->right && node2->right) {
                q.push(node1->right);
                q.push(node2->right);
                visited.insert(node1);
                visited.insert(node2);
            }
        }
        return q.empty();
    }
};
