#include "../header.h"

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root) {
            queue<TreeNode*> q;
            q.push(root);
            bool meetNull = false;
            while (!q.empty()) {
                int sz = q.size();
                bool hasNullCurrentLevel = false, allNullCurrentLevel = true;
                while (sz > 0) {
                    TreeNode *n = q.front();
                    q.pop();
                    if (n != nullptr) {
                        if (hasNullCurrentLevel) {
                            return false;
                        }
                        allNullCurrentLevel = false;
                        q.push(n->left);
                        q.push(n->right);
                    } else {
                        hasNullCurrentLevel = true;
                        q.push(nullptr);
                        q.push(nullptr);
                    }             
                    --sz;
                }
                if (allNullCurrentLevel) {
                    return true;
                }
                if (hasNullCurrentLevel) {
                    if (meetNull) {
                        return false;
                    }
                    meetNull = true;
                }
            }
        }
        return true;
    }
};