#include "../header.h"

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int index = 0;
        return construct(preorder, postorder, index, 0, postorder.size() - 1);
    }

    TreeNode* construct(vector<int>& pre, vector<int>& post, int& index, int l, int h) {
        if (index >= pre.size() || l > h) 
            return nullptr;

        TreeNode* root = new TreeNode(pre[index++]);
        if (l == h) return root;

        int i = l;
        while (i <= h && post[i] != pre[index]) i++;

        if (i <= h) {
            root->left = construct(pre, post, index, l, i);
            root->right = construct(pre, post, index, i + 1, h - 1);
        }

        return root;
    }
};