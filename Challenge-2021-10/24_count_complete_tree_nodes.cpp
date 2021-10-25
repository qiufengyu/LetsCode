#include "../header.h"

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root) {
            return countNodes(root->left) + countNodes(root->right) + 1;
        } else {
            return 0;
        }        
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode* root = stringToTreeNode(s);
    cout << Solution().countNodes(root) << endl;
    return 0;
}