#include "../header.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
            while (!q.empty()) {
                int sz = q.size();
                vector<int> v;
                while (sz > 0) {
                    TreeNode *n = q.front();
                    q.pop();
                    v.push_back(n->val);
                    if (n->left) {
                        q.push(n->left);
                    }
                    if (n->right) {
                        q.push(n->right);
                    }
                    --sz;
                }
                res.push_back(v);
            }
        }
        return res;
    }
};