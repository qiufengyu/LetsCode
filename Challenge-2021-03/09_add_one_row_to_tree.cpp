#include "../header.h"

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {        
        if (d == 1) {
            TreeNode* h = new TreeNode{v};
            h->left = root;
            return h;
        }
        // d >= 2
        queue<TreeNode*> q;
        q.push(root);
        int l = 1;
        while (!q.empty() && l < d - 1) {
            ++l;            
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode *t = q.front();
                q.pop();
                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
            }            
        }
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            TreeNode *t = q.front();
            q.pop();            
            TreeNode *tl = new TreeNode{v};
            tl->left = t->left;
            t->left = tl;
            TreeNode *tr = new TreeNode{v};
            tr->right = t->right;
            t->right = tr;            
        }
        return root;
    }
};