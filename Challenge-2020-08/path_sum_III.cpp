#include "../header.h"

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        vector<TreeNode*> v;
        helper(root, sum, 0, v, res);
        return res;
    }

    void helper(TreeNode* node, const int sum, int current, vector<TreeNode*>& v, int& res) {
        if (node == nullptr) {
            return;
        }
        v.push_back(node);
        current += node->val;        
        if (current == sum) {
            res += 1;
        }
        int temp = current;
        for (int i = 0; i < v.size() - 1; i++) {
            temp -= v[i]->val;
            if (temp == sum) {
                res += 1;
            }
        }        
        helper(node->left, sum, current, v, res);
        helper(node->right, sum, current, v, res);
        v.pop_back();
    }
};

int main() {
    string s;
    cin >> s;
    int sum;
    cin >> sum;
    TreeNode *root = stringToTreeNode(s);
    cout << Solution().pathSum(root, sum) << endl;
    return 0;
    
}