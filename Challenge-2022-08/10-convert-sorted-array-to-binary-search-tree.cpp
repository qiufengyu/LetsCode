#include "../header.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        } else if (start == end) {
            return new TreeNode(nums[start]);
        } else {
            int m = start + (end - start) / 2;
            TreeNode *node = new TreeNode(nums[m]);
            node->left = helper(nums, start, m - 1);
            node->right = helper(nums, m + 1, end);
            return node;
        }
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> arr = stringToIntegerVector(s);
    TreeNode* root = Solution().sortedArrayToBST(arr);
    prettyPrintTree(root);
    return 0;
}