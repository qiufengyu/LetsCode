#include "../header.h"

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        traverse(root, nums);
        return construct(nums, 0, nums.size() - 1);
    }

    void traverse(TreeNode* node, vector<int>& nums) {
        if (node) {            
            traverse(node->left, nums);
            nums.push_back(node->val);
            traverse(node->right, nums);
        }
    }

    TreeNode* construct(vector<int>& nums, int l, int r) {
        if (l <= r) {
            int m = (l + r) / 2;
            int val = nums[m];
            TreeNode *node = new TreeNode{val, construct(nums, l, m - 1), construct(nums, m + 1, r)};
            return node;
        }
        return nullptr;
    }
};