class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);

        vector<int> ans;
        while (!q.empty()) {
            int size = q.size();
            bool chose_node_from_layer = false;
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();

                if (!chose_node_from_layer) {
                    ans.push_back(node->val);
                    chose_node_from_layer = true;
                }

                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
            }
        }
        return ans;
    }
};
