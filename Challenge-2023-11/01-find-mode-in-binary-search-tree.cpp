#include "../header.h"

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        unordered_map<int, int> counter;
        dfs(root, counter);
        int maxCount = 0;
        for (auto const& p: counter) {
            if (p.second > maxCount) {
                maxCount = p.second;
            }
        }       
        for (auto const& p: counter) {
            if (p.second == maxCount) {
                res.push_back(p.first);
            }
        }
        return res;
    }

    void dfs(TreeNode* node, unordered_map<int, int>& counter) {
        if (node) {
            ++counter[node->val];
            dfs(node->left, counter);
            dfs(node->right, counter);
        }
    }
};