#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

// n == # of nodes
// runtime: O(n)
// space: O(n)
vector<double> average_of_levels(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    vector<double> result;
    while (!q.empty()) {
        long sum = 0;
        int count = q.size();
        for (int i = 0; i < count; i++) {
            TreeNode* node = q.front();
            sum += node->val;
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
            q.pop();
        }
        double avg = static_cast<double>(sum) / count;
        result.push_back(avg);
    }

    return result;
}

int main() {
    cout << fixed << setprecision(2);

    TreeNode* root =
        new TreeNode(3, new TreeNode(9),
                     new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    vector<double> result = average_of_levels(root);  // [3, 14.5, 11]
    for (double d : result) {
        cout << d << ' ';
    }
    cout << '\n';
}
