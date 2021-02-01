#include "../header.h"

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int, vector<int>> om;
        if (root) {
          queue<pair<int, TreeNode*>> q;
          q.emplace(0, root);
          while (!q.empty()) {
            int sz = q.size();
            map<int, vector<int>> m;
            while (sz > 0) {
              auto e = q.front();
              q.pop();
              m[e.first].push_back(e.second->val);
              if (e.second->left) {
                q.emplace(e.first-1, e.second->left);
              }
              if (e.second->right) {
                q.emplace(e.first+1, e.second->right);
              }
              sz--;
            }
            for (auto e: m) {
              sort(e.second.begin(), e.second.end());
              if (om.count(e.first)) {
                  om[e.first].insert(om[e.first].end(), e.second.begin(), e.second.end());
              } else {
                  om[e.first] = e.second;
              }
            }
          }
          for (auto e: om) {
            res.push_back(e.second);
          }
        }
        
        return res;
    }
};