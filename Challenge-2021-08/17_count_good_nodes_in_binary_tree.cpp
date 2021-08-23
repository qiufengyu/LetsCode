#include "../header.h"

class Solution {
public:
    int goodNodes(TreeNode* root) {        
        if (root == nullptr) {
            return 0;
        }
        vector<int> paths;
        int count = 0;
        dfs(root, paths, count);
        return count;        
    }

    void dfs(TreeNode *node, vector<int>& paths, int& count) {
        paths.push_back(node->val);
        auto currentMax = *max_element(paths.begin(), paths.end());
        if (node->val >= currentMax) {
            ++count;
        }
        if (node->left) {
            dfs(node->left, paths, count);
        }
        if (node->right) {
            dfs(node->right, paths, count);
        }
        paths.pop_back();
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode *root = stringToTreeNode(s);
    cout << Solution().goodNodes(root) << endl;
    return 0;
}