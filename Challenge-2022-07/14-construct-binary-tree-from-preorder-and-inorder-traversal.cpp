#include "../header.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, 0, inorder.size()-1);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, 
                     int preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }
        int parent = preorder[preIndex];
        int i = inStart;
        while(i <= inEnd) {
            if (inorder[i] == parent) {
                break;
            }
            ++i;      
        }
        TreeNode *p = new TreeNode(parent);
        p->left = helper(preorder, inorder, preIndex+1, inStart, i-1);
        p->right = helper(preorder, inorder, preIndex+i-inStart+1, i+1, inEnd);
        return p;
    }
};