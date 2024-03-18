#include "../header.h"

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = root->val;
        while (!q.empty()) {
            int sz = q.size();
            res = q.front()->val;
            while (sz) {
                TreeNode *frt = q.front();
                q.pop();
                if (frt->left) {
                    q.push(frt->left);
                }
                if (frt->right) {
                    q.push(frt->right);
                }
                --sz;
            }
        }
        return res;
    }
};