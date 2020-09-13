#include "../header.h"

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        if (root) {
            int temp = 0;
            traversal(root, sum, temp);
        }
        return sum;        
    }

    void traversal(TreeNode *root, int& sum, int temp) {
        if (root->left || root->right) {
            temp = temp * 2 + root->val;
            if (root->left) {                
                traversal(root->left, sum, temp);
            }
            if (root->right) {
                traversal(root->right, sum, temp);
            }
        } else {
            sum += (temp * 2 + root->val);
        }        
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode *root = stringToTreeNode(s);
    cout << Solution().sumRootToLeaf(root) << endl;
    return 0;
}