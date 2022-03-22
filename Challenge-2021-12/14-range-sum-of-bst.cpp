#include "../header.h"

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int res = 0;
        helper(root, low, high, res);
        return res;
    }

    void helper(TreeNode* root, const int low, const int high, int& res) {
        if (root == nullptr) {
            return;
        }
        if (root->val < low) {
            helper(root->right, low, high, res);
        }
        else if (root->val > high) {
            helper(root->left, low, high, res);
        } else {
            res += root->val;
            helper(root->left, low, high, res);
            helper(root->right, low, high, res);
        }
    }
};

int main() {
    string s;
    cin >> s;
    int l, r;
    cin >> l >> r;
    TreeNode* root = stringToTreeNode(s);
    cout << Solution().rangeSumBST(root, l, r) << endl;
    return 0;
}