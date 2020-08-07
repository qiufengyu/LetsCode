#include "header.h"

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root == nullptr) return res;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;
            while (size > 0) {
                TreeNode *n = q.front();
                q.pop();
                v.push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
                size--;
            }
            res.push_back(v);
        }
        reverse(res.begin(), res.end());
        return res;       
    }
};

int main() {
    string s {"[]"};
    TreeNode *root = stringToTreeNode(s);
    vector<vector<int>> r = Solution().levelOrderBottom(root);
    print_vector(r);
    return 0;
}