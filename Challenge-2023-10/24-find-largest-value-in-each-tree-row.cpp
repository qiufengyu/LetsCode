#include "../header.h"

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
            while (!q.empty()) {
                int sz = q.size();
                int mx = q.front()->val;
                while (sz > 0) {
                    TreeNode *tn = q.front();
                    q.pop();
                    mx = max(mx, tn->val);
                    if (tn->left) {
                        q.push(tn->left);
                    }
                    if (tn->right) {
                        q.push(tn->right);
                    }
                    --sz;
                }
                res.push_back(mx);
            }
        }
        return res;
    }
};