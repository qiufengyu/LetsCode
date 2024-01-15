#include "../header.h"

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> s1, s2;
        helper(root1, s1);
        helper(root2, s2);
        return s1 == s2;
    }

    void helper(TreeNode* node, vector<int>& seq) {
        if (node) {
            if (node->left || node->right) {
                helper(node->left, seq);
                helper(node->right, seq);
            } else {
                seq.push_back(node->val);
            }
        }
    }
};