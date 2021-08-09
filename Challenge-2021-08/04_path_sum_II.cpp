#include "../header.h"

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;
        int current = 0;
        helper(root, targetSum, res, temp, current);
        return res;        
    }

    void helper(TreeNode* node, const int targetSum, vector<vector<int>>& res, vector<int>& temp, int& current) {
        if (node != nullptr) {
            current += node->val;
            temp.push_back(node->val);
            if (node->left == nullptr && node->right == nullptr && current == targetSum) {
                res.push_back(temp);
            }
            helper(node->left, targetSum, res, temp, current);
            helper(node->right, targetSum, res, temp, current);
            current -= node->val;
            temp.pop_back();
        }
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode *root = stringToTreeNode(s);
    int t;
    cin >> t;
    auto res = Solution().pathSum(root, t);
    print_vector<int>(res);
    return 0;
}