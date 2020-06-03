#include <iostream>
#include <vector>

#include "binary_tree.h"

using namespace std;

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode {preorder[0]};
        for (int i = 1; i < preorder.size(); i++) {
            TreeNode *parent = nullptr;
            TreeNode *child = root;
            // TreeNode *child = root;
            int val = preorder[i];
            while (child) {
                parent = child;
                if (child->val < val) {                    
                    child = child->right;
                } else {
                    child = child->left;
                }
            }
            if (parent->val < val) {
                parent->right = new TreeNode {val};
            } else {
                parent->left = new TreeNode {val};
            }
        }
        return root;        
    }
};

int main() {
    vector<int> v {8, 5, 1, 7, 10, 12};
    TreeNode* root = Solution().bstFromPreorder(v);
    prettyPrintTree(root);
}