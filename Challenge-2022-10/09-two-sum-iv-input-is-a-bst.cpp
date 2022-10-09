#include "../header.h"

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return helper(root, st, k);        
    }

    bool helper(TreeNode* node, unordered_set<int>& st, int const k) {
        if (node) {
            int val = node->val;
            if (st.count(k - val)) {
                return true;
            }
            st.emplace(val);
            return helper(node->left, st, k) || helper(node->right, st, k);
        }
        return false;
    }
};