#include "../header.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pPath, qPath;
        pPath.push_back(root);
        qPath.push_back(root);
        getPath(p->val, pPath);
        for (auto const node: pPath) {
            cout << node->val << " ";
        }
        cout << endl;
        getPath(q->val, qPath);
        for (auto const node: qPath) {
            cout << node->val << " ";
        }
        cout << endl;
        TreeNode* res = root;
        for (int i = 0; i < pPath.size() && i < qPath.size(); ++i) {
            if (pPath[i]->val != qPath[i]->val) {
                break;
            }
            res = pPath[i];
        }
        return res;
    }

    bool getPath(const int val, vector<TreeNode*>& path) {
        TreeNode* last = path.back();
        if (last->val == val) {
            return true;
        }
        if (last->left) {
            path.push_back(last->left);
            if (getPath(val, path)) {
                return true;
            } else {
                path.pop_back();
            }
        }
        if (last->right) {
            path.push_back(last->right);
            if (getPath(val, path)) {
                return true;
            } else {
                path.pop_back();
            }
        }
        return false;
    }
};

int main() {
    TreeNode* root = stringToTreeNode("[3,5,1,6,2,0,8,null,null,7,4]");
    TreeNode *p = new TreeNode(3);
    TreeNode *q = new TreeNode(5);
    cout << (Solution().lowestCommonAncestor(root, p, q))->val << endl;
    return 0;
}