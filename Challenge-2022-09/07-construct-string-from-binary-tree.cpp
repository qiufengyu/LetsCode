#include "../header.h"

class Solution {
public:
    string tree2str(TreeNode* root) {
        string res;
        helper(root, res);
        return res;        
    }

    void helper(TreeNode* node, string& res) {
        if (node) {
            res.append(to_string(node->val));
            if (node->left) {
                res.append("(");
                helper(node->left, res);
                res.append(")");
            }
            if (node->right) {
                if (node->left == nullptr) {
                    res.append("()");
                }
                res.append("(");
                helper(node->right, res);
                res.append(")");
            }
        }
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode *root = stringToTreeNode(s);
    string res = Solution().tree2str(root);
    cout << res << endl;
    return 0;
}