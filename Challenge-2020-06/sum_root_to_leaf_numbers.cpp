#include "header.h"

class Solution {
public:
    void helper(TreeNode *t, int &res, string& num) {
        if (t->left == nullptr && t->right == nullptr) {
            num.push_back('0' + t->val);
            // cout << "Num: " << num << endl;
            res += stoi(num);
            num.pop_back();
        }
        if (t->left) {
            num.push_back('0' + t->val);
            helper(t->left, res, num);
            num.pop_back();
        }
        if (t->right) {
            num.push_back('0' + t->val);
            helper(t->right, res, num);
            num.pop_back();
        }   
    }
    int sumNumbers(TreeNode* root) {
        int res = 0;
        string num = "";
        if (root == nullptr) {
            return 0;
        }
        helper(root, res, num);
        return res;                
    }
};

int main() {
    string tree {"[4,9,0,5,1]"};
    TreeNode *root = stringToTreeNode(tree);
    cout << Solution().sumNumbers(root) << endl;
    return 0;
}
