#include "../header.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pPath, qPath, pRes, qRes;
        dfs(root, p->val, pPath, pRes);
        dfs(root, q->val, qPath, qRes);
        int pLength = pRes.size(), qLength = qRes.size();
        TreeNode *res = root;
        int i = 0;
        while (i < min(pLength, qLength)) {
            if (pRes[i]->val != qRes[i]->val) {
                break;
            } else {
                res = pRes[i];
                i++;
            }
        }
        return res;
    }

    void dfs(TreeNode* node, int val, vector<TreeNode*>& path, vector<TreeNode*>& res) {
        if (node) {
            path.push_back(node);
            if (node->val != val) {
                dfs(node->left, val, path, res);
                if (node->left) {
                    path.pop_back();
                }
                dfs(node->right, val, path, res);
                if (node->right) {
                    path.pop_back();
                }
            } else {
                res = path;
            }
        }
    }
};

int main() {
    string s;
    cin >> s;
    int p, q;
    cin >> p >> q;
    TreeNode* root = stringToTreeNode(s);
    TreeNode *pNode = new TreeNode(p), *qNode = new TreeNode(q);
    TreeNode *res = Solution().lowestCommonAncestor(root, pNode, qNode);
    cout << res->val << endl;
    return 0;
}