#include "../header.h"

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int nodes = preorder.size();
        TreeNode *res = helper(preorder, 0, nodes - 1, nodes);
        return res;
    }

    TreeNode *helper(vector<int>& preorder, int start, int end, const int n) {
        if (start >= n || end >= n || start > end) {
            return nullptr;
        }
        int rootVal = preorder[start];
        TreeNode *node = new TreeNode(preorder[start]);
        int split = start + 1;
        while (split <= end) {
            if (preorder[split] > rootVal) {
                break;
            }
            split++;
        }
        node->left = helper(preorder, start + 1, split - 1, n);
        node->right = helper(preorder, split, end, n);
        return node;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> preorder = stringToIntegerVector(s);
    TreeNode *root = Solution().bstFromPreorder(preorder);
    prettyPrintTree(root);
    return 0;
}