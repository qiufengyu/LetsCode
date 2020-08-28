#include "../header.h"

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if (root != nullptr) {
            helper(root, sum, false);
        }
        return sum;
    }

    void helper(TreeNode* node, int& sum, bool b) {
        
        if (node->left == nullptr && node->right == nullptr) {
            if (b) {
                sum += node->val;
            }
        } else {
            if (node->left) {
                helper(node->left, sum, true);
            }
            if (node->right) {
                helper(node->right, sum, false);
            }
        }
    }
};

int main() {
    string s {"[3,9,20,null,null,15,7]"};
    TreeNode *root = stringToTreeNode(s);
    cout << Solution().sumOfLeftLeaves(root) << endl;
    return 0;

}