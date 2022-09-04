#include "../header.h"

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
            while (!q.empty()) {
                long s = 0L;
                int sz = q.size();
                for (int i = 0; i < sz; ++i) {
                    TreeNode *n = q.front();
                    s += n->val;
                    if (n->left) {
                        q.push(n->left);
                    }
                    if (n->right) {
                        q.push(n->right);
                    }
                    q.pop();
                }
                res.push_back((double) s / sz);
            }
        }
        return res;
    }
};