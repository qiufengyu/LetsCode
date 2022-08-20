#include "../header.h"

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root) {
            queue<TreeNode*> q;
            q.push(root);
            TreeNode *node = nullptr;
            int sz = q.size();
            while (!q.empty()) {
                sz = q.size();
                while (sz > 1) {
                    node = q.front();
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                    q.pop();
                    --sz;
                }
                node = q.front();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                q.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};