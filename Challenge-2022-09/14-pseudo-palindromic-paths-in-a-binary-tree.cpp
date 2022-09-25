#include "../header.h"

class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> path(10, 0);
        int res = 0;
        dfs(root, path, res);
        return res;
    }

    void dfs(TreeNode* node, vector<int>& path, int& res) {
        if (node) {
            ++path[node->val];
            if (node->left == nullptr && node->right == nullptr) {
                // check path
                int odd = 0;
                print_vector<int>(path);
                for (int i = 1; i < 10; ++i) {                    
                    if (path[i] % 2 == 1) {
                        ++odd;
                    }
                }
                if (odd <= 1) {
                    ++res;
                }
                --path[node->val];
                return;
            }
            if (node->left) {
                dfs(node->left, path, res);
            }
            if (node->right) {
                dfs(node->right, path, res);
            }
            --path[node->val];
        }
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode *root = stringToTreeNode(s);
    cout << Solution().pseudoPalindromicPaths(root) << endl;
    return 0;
}