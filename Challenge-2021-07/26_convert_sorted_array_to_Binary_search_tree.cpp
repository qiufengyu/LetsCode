#include "../header.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int sz = nums.size();
        TreeNode *root = build(nums, 0, sz - 1);
        return root;
    }

    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l > r) {
            return nullptr;
        } else if (l == r) {
            // leaf node
            return new TreeNode(nums[l]);
        } else {
            int m = (l + r) / 2;
            TreeNode *parent = new TreeNode(nums[m]);
            parent->left = build(nums, l, m-1);
            parent->right = build(nums, m+1, r);
            return parent;
        }
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> nums = stringToIntegerVector(s);
    prettyPrintTree(Solution().sortedArrayToBST(nums));
    return 0;
}