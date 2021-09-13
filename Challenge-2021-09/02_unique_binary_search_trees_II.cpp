#include "../header.h"

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
    
    vector<TreeNode*> helper(int start, int end) {
        if (start > end) {
            return {nullptr};
        }
        vector<TreeNode*> res;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = helper(start, i - 1), right = helper(i + 1, end);
            for (auto ln: left) {
                for (auto rn: right) {
                    TreeNode *n = new TreeNode(i);
                    n -> left = ln;
                    n -> right = rn;
                    res.push_back(n);
                }
            }
        }
        return res;
    }
};