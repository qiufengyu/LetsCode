#include "../header.h"

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        int res = 0;
        if (root) {
            q.push({root, 0LL});
            while (!q.empty()) {
                int sz = q.size();
                int t1 = (int)(q.front().second);
                int t2 = (int)(q.back().second);
                res = max(t2 - t1 + 1, res);
                while (sz > 0) {
                    auto f = q.front();
                    q.pop();
                    TreeNode* n = f.first;
                    int t = (int)f.second;
                    if (n->left) {
                        q.push({n->left, t * 2LL + 1});
                    }
                    if (n->right) {
                        q.push({n->right, t * 2LL + 2});
                    } 
                    --sz;
                }                
            }
        }
        return res;
    }
};