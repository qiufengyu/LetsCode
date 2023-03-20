#include "../header.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int istart = 0, iend = inorder.size() - 1, pstart = 0, pend = postorder.size() - 1;
        return build(inorder, istart, iend, postorder, pstart, pend);
    }

    TreeNode* build(vector<int>& inorder, int istart, int iend, vector<int>& postorder, int pstart, int pend) {
        if (istart > iend || pstart > pend) {
            return nullptr;
        }
        TreeNode *node = new TreeNode(postorder[pend]);
        int i = istart;
        for (i = istart; i <= iend; ++i) {
            if (inorder[i] == postorder[pend]) {
                break;
            }
        }
        node->left = build(inorder, istart, i - 1, postorder, pstart, pstart + i - istart - 1);
        node->right = build(inorder, i + 1, iend, postorder, pstart + i - istart, pend - 1);
        return node;
    }
};