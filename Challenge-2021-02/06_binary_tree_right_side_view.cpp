#include "../header.h"

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        deque<TreeNode*> dq; 
        vector<int> res;
        if (root) {
          dq.push_back(root);
          while (!dq.empty()) {
            int sz = dq.size();
            auto tail = dq.back();
            res.push_back(tail->val);
            while (sz > 0) {
              TreeNode* n = dq.front();
              dq.pop_front();
              if (n->left) {
                dq.push_back(n->left);
              }
              if (n->right) {
                dq.push_back(n->right);
              }
              sz--;
            }
          }
        }
        return res;
    }
};