#include "../header.h"

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*, long long>> q;
        q.push_back({root, 0});
        int res = 0;
        while (!q.empty()) {
            int sz = q.size();
            pair<TreeNode*, int> t1 = q.front(), t2 = q.back();
            res = max(res, t2.second - t1.second + 1);
            for (int i = 0; i < sz; ++i) {    
                t1 = q.front();
                q.pop_front();        
                if (t1.first->left != nullptr) {
                    q.push_back({t1.first->left, (2 * ((long long)t1.second) + 1)});
                }
                if (t1.first->right != nullptr) {
                    q.push_back({t1.first->right, (2 * ((long long)t1.second) + 2)});
                }
            }
        }
        return res;
    }
};
