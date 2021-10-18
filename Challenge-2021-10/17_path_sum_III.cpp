#include "../header.h"

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> prefix;
        prefix[0] = 1;
        return dfs(root, targetSum, 0, prefix);        
    }

    int dfs(TreeNode* node, const int targetSum, int current, unordered_map<int, int>& prefix) {
        if (node) {
            int res = 0;
            current += node->val;
            if (prefix.count(current - targetSum)) {
                res = prefix[current-targetSum];
            }
            ++prefix[current];
            res += dfs(node->left, targetSum, current, prefix);
            res += dfs(node->right, targetSum, current, prefix);
            --prefix[current];
            return res;
        }
        return 0;
    }
};