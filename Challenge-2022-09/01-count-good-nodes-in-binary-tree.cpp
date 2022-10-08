#include "../header.h"

class Solution {
public:
    int goodNodes(TreeNode* root) {
        vector<int> currentMax;
        int res = 0;
        if (root) {
            dfs(root, currentMax, res);
        }
        return res;
    }

    void dfs(TreeNode *node, vector<int>& currentMax, int& res) {
        if (currentMax.empty()) {
            currentMax.push_back(node->val);
        } else {
            currentMax.push_back(max(node->val, currentMax.back()));
        }
        if (node->left) {                
            dfs(node->left, currentMax, res);                
        }
        if (node->right) {
            dfs(node->right, currentMax, res);
        }
        currentMax.pop_back();
        if (currentMax.empty() || node->val >= currentMax.back()) {
            ++res;
        }        
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode *root = stringToTreeNode(s);
    int res = Solution().goodNodes(root);
    cout << res << endl;
    return 0;
}