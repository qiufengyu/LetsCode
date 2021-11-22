#include "../header.h"

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* dummy = new TreeNode(-1);
        dummy->left = root;
        helper(dummy->left, dummy, key, true);
        return dummy->left;        
    }

    void helper(TreeNode* current, TreeNode* parent, const int key, bool leftOrRight) {
        if (current->val == key) {
            // find the right most of the left child / left most of the right child
            TreeNode *l = current->left, *r = current->right;
            TreeNode *p = current;
            if (l) {
                bool flag = false;
                while (l->right != nullptr) {
                    p = l;
                    l = l->right;
                    flag = true;
                }
                current->val = l->val;
                if (flag) {
                    p->right = l->left;
                } else {
                    p->left = l->left;
                }
            } else if (r) {
                bool flag = false;
                while (r->left != nullptr) {
                    p = r;
                    r = r->left;
                    flag = true;
                }
                current->val = r->val;
                if (flag) {
                    p->left = r->right;
                } else {
                    p->right = r->right;
                }
            } else {
                if (leftOrRight) {
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }
            }
        }
        else if (current->left && current->val > key) {
            helper(current->left, current, key, true);
        }
        else if (current->right && current->val < key) {
            helper(current->right, current, key, false);
        }
    }
};

int main() {
    string s;
    cin >> s;
    int key;
    cin >> key;
    TreeNode *root = stringToTreeNode(s);
    TreeNode *res = Solution().deleteNode(root, key);
    prettyPrintTree(res);
    return 0;
}