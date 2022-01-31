#include "../header.h"

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res, res1, res2;
        if (root1) {
            helper(root1, res1);
        }
        if (root2) {
            helper(root2, res2);
        }
        int i = 0, j = 0;
        while (i < res1.size() && j < res2.size()) {
            if (res1[i] < res2[j]) {
                res.push_back(res1[i++]);
            } else {
                res.push_back(res2[j++]);
            }
        }
        while (i < res1.size()) {
            res.push_back(res1[i++]);
        }
        while (j < res2.size()) {
            res.push_back(res2[j++]);
        }
        return res;
    }

    void helper(TreeNode* node, vector<int>& res) {
        if (node->left) {
            helper(node->left, res);
        }
        res.push_back(node->val);
        if (node->right) {
            helper(node->right, res);
        }
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    TreeNode* root1 = stringToTreeNode(s1);
    TreeNode* root2 = stringToTreeNode(s2);
    vector<int> res = Solution().getAllElements(root1, root2);
    print_vector<int>(res);
    return 0;
}