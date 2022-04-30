#include "../header.h"

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = 0, current = 0;
        helper(root, k, current, res);
        return res;
    }

    void helper(TreeNode *root, const int k, int& current, int& res) {
        if (root) {            
            helper(root->left, k, current, res);
            cout << current << ": " << root->val << endl;
            current++;
            if (current == k) {
                res = root->val;
            }
            helper(root->right, k, current, res);            
        }
    }
};

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    TreeNode *root = stringToTreeNode(s);
    cout << Solution().kthSmallest(root, k) << endl;
    return 0;
}