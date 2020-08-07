#include "header.h"

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

int main() {
    string s1 {"[1,2,1]"};
    string s2 {"[1,1,2]"};
    TreeNode *t1 = stringToTreeNode(s1);
    TreeNode *t2 = stringToTreeNode(s2);
    cout << Solution().isSameTree(t1, t2) << endl;
    return 0;
}