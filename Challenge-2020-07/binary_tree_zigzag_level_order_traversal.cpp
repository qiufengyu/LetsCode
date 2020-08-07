#include "../header.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        bool flag = false;
        q.push(root);        
        while (!q.empty()) {
            int sz = q.size();
            vector<int> v;
            while (sz > 0) {
                TreeNode *t = q.front();
                q.pop();
                v.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                sz--;
            }
            if (flag) {
                reverse(v.begin(), v.end());
            }
            flag = !flag;
            ans.push_back(v);
        }
        return ans;                
    }
};

int main() {

}