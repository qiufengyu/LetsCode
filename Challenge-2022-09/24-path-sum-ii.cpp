#include "../header.h"

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> current;
        helper(root, targetSum, res, current, 0);
        return res;
    }
    
    void helper(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int>& current, int currentSum) {
        if (root) {
            current.push_back(root->val);
            currentSum += root->val;
            if (root->left == nullptr && root->right == nullptr && currentSum == targetSum) {
                res.push_back(current);
            }
            helper(root->left, targetSum, res, current, currentSum);
            helper(root->right, targetSum, res, current, currentSum);
            currentSum -= root->val;
            current.pop_back();
        }
    }
};