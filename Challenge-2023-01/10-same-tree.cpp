#include "../header.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) {
            return (p == nullptr && q == nullptr);
        } else {
            if (p->val == q->val) {
                return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
            }
            return false;
        }
    }
};
