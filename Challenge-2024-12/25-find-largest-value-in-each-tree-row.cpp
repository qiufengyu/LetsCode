#include "../header.h"

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int mx = INT_MIN;
            int sz = q.size();
            while (sz) {
                TreeNode* frt = q.front();
                q.pop();
                mx = max(mx, frt->val);
                if (frt->left) {
                    q.push(frt->left);
                }
                if (frt->right) {
                    q.push(frt->right);
                }
                sz--;
            }
            res.push_back(mx);
        }
        return res;
    }
};