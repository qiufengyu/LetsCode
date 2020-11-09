#include "../header.h"

class Solution {
public:
    int findTilt(TreeNode* root) {
        int res = 0;
        if (root)
            calcTilt(root, res);
        return res;
    }

    int calcTilt(TreeNode* root, int& res) {
        int l = 0, r = 0;
        if (root->left) {
            l = calcTilt(root->left, res);
        }
        if (root->right) {
            r = calcTilt(root->right, res);
        }
        res += abs(l - r);
        // cout << root->val << ": " << abs(l - r) << endl;
        return root->val + l + r;
    }
};