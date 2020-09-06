#include "../header.h"

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        traversal(root1, v1);
        traversal(root2, v2);
        vector<int> res;
        int sz1 = v1.size(), sz2 = v2.size();
        int i = 0, j = 0;
        while (i < sz1 && j < sz2) {
            if (v1[i] < v2[j]) {
                res.push_back(v1[i++]);
            } else {
                res.push_back(v2[j++]);
            }
        }
        while (i < sz1) {
            res.push_back(v1[i++]);
        }
        while (j < sz2) {
            res.push_back(v2[j++]);
        }
        return res;
    }

    void traversal(TreeNode *root, vector<int>& v) {
        if (root) {
            traversal(root->left, v);
            v.push_back(root->val);
            traversal(root->right, v);
        }
    }
};


int main() {
    string t1, t2;
    cin >> t1 >> t2;
    TreeNode *root1 = stringToTreeNode(t1);
    TreeNode *root2 = stringToTreeNode(t2);
    vector<int> res = Solution().getAllElements(root1, root2);
    print_vector<int>(res);
    return 0;
}