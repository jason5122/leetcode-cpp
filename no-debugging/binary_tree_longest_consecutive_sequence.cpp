/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        stack<pair<TreeNode*, TreeNode*>> stk;  // {curr, prev}
        stack<int> counts;
        unordered_set<TreeNode*> visited;

        stk.push({root, nullptr});
        counts.push(1);
        visited.insert(root);

        int ans = 1;
        while (!stk.empty()) {
            auto [curr, prev] = stk.top();
            int count = counts.top();
            stk.pop();
            counts.pop();

            if (prev && curr->val == prev->val + 1) {
                count++;
                ans = max(count, ans);
            } else {
                count = 1;
            }

            if (curr->left && !visited.count(curr->left)) {
                stk.push({curr->left, curr});
                counts.push(count);
                visited.insert(curr->left);
            }
            if (curr->right && !visited.count(curr->right)) {
                stk.push({curr->right, curr});
                counts.push(count);
                visited.insert(curr->right);
            }
        }
        return ans;
    }
};
