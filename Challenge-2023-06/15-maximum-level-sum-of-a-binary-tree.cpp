#include "../header.h"

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 1, mx = root->val, res = 1;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size(), sum = 0;
            while (sz > 0) {
                TreeNode* n = q.front();
                q.pop();
                sum += n->val;
                if (n->left) {
                    q.push(n->left);
                }
                if (n->right) {
                    q.push(n->right);
                }
                --sz;
            }
            if (sum > mx) {
                mx = sum;
                res = level;
            }
            ++level;
        }
        return res;
    }
};