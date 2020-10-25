#include "../header.h"

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root) {
            int res = 100001;
            depth(root, res, 1);
            return res;
        }
        return 0;
    }

    void depth(TreeNode* root, int &d, int level) {
        if (!root) {
            return;
        }
        if (root->left || root->right) {
            depth(root->left, d, level + 1);
            depth(root->right, d, level + 1);
        } else {
            if (level < d) {
                d = level;
            }
        }

    }
};

int main() {
    string s;
    cin >> s;
    TreeNode* root = stringToTreeNode(s);
    cout << Solution().minDepth(root) << endl;
    return 0;
}