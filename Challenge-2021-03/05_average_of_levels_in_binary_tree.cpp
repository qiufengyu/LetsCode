#include "../header.h"

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (root) {
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                int sz = q.size();
                int i = sz;
                long long int sum = 0;
                while (i > 0) {
                    TreeNode *t = q.front();
                     q.pop();
                    if (t->left) {
                        q.push(t->left);
                    }
                    if (t->right) {
                        q.push(t->right);
                    }
                    sum += t->val;
                    i--;
                }
                res.push_back((double)sum / sz);
            }
        }
        return res;
    }
};