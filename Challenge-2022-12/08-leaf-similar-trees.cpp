#include "../header.h"

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        dfs(root1, v1);
        dfs(root2, v2);
        return v1 == v2;
    }

    void dfs(TreeNode* node, vector<int>& leaves) {
        if (node) {
            if (node->left == nullptr && node->right == nullptr) {
                leaves.push_back(node->val);
            } else {
                if (node->left) {
                    dfs(node->left, leaves);
                }
                if (node->right) {
                    dfs(node->right, leaves);
                }
            }
        }
    }
};