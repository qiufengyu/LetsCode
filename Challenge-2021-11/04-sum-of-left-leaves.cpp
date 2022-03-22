#include "../header.h"

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int res = 0;
        dfs(root, res, false);
        return res;
    }

    void dfs(TreeNode* node, int& res, bool b) {
        if (node->left == nullptr && node->right == nullptr) {
            res += (b ? node->val : 0);
            return;
        }
        if (node->left) {
            dfs(node->left, res, true);
        }
        if (node->right) {
            dfs(node->right, res, false);
        }        
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode *root = stringToTreeNode(s);
    cout << Solution().sumOfLeftLeaves(root) << endl;
    return 0;
}