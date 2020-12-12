#include "../header.h"

class BSTIterator {
  stack<TreeNode*> s;
  TreeNode* current;
public:
    BSTIterator(TreeNode* root) {
        current = root;
    }
    
    int next() {
        while (current) {
          s.push(current);
          current = current->left;
        }
        current = s.top();
        s.pop();
        int val = current->val;
        current = current->right;
        return val;
    }
    
    bool hasNext() {
        return !s.empty() || current;
    }
};