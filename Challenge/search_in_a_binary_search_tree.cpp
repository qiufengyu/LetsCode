#include "header.h"

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *n = root;
        while (n && n->val != val ) {
            if (n->val < val) {
                n = n->right;
            } else if (n->val > val){
                n = n->left;
            }
        }
        return n;
    }
};

int main() {
    string tree {"[4,2,7,1,3]"};
    TreeNode *root = stringToTreeNode(tree);
    int val = 2;
    cout << treeNodeToString(Solution().searchBST(root, val)) << endl;
    return 0;
}