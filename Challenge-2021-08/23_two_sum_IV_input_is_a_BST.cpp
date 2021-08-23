#include "../header.h"

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) {
            return false;
        }
        unordered_set<int> m;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode* n = q.front();
                q.pop();
                if (m.count(n->val) > 0) {
                    return true;
                }
                m.insert(k - n->val);
                if (n->left) {
                    q.push(n->left);
                }
                if (n->right) {
                    q.push(n->right);
                }
            }
        }
        return false;
    }
};

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    TreeNode* root = stringToTreeNode(s);
    cout << Solution().findTarget(root, k) << endl;
    return 0;
}