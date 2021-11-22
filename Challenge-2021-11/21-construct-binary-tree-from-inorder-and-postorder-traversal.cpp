#include "../header.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int length = inorder.size() - 1;
        TreeNode *root = helper(inorder, postorder, 0, length, 0, length, length);
        return root;
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr, const int length) {
        if (il > ir || pl > pr) {
            return nullptr;
        }
        int val = postorder[pr];
        TreeNode *node = new TreeNode(val);
        int index = 0;
        for (int i = 0; i <= length; ++i) {
            if (inorder[i] == val) {
                index = i;
                break;
            }
        }
        node->left = helper(inorder, postorder, il, index-1, pl, (pl + index - il - 1), length);
        node->right = helper(inorder, postorder, index+1, ir, (pr-ir+index), pr-1, length);
        return node;
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> inorder = stringToIntegerVector(s1), postorder = stringToIntegerVector(s2);
    TreeNode *root = Solution().buildTree(inorder, postorder);
    prettyPrintTree(root);
    return 0;
}