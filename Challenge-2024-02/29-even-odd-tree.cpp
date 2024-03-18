#include "../header.h"

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size() - 1;
            TreeNode* frt = q.front();
            q.pop();
            int prev = frt->val;
            if ((level % 2 == 0) == (prev % 2 == 0)) {
                cout << "False at prev % 2 == level % 2" << endl;
                return false;
            }
            if (frt->left) {
                q.push(frt->left);
            }
            if (frt->right) {
                q.push(frt->right);
            }            
            while (sz) {
                frt = q.front();
                q.pop();
                int nxt = frt->val;
                if ((level % 2 == 0) == (nxt % 2 == 0)) {
                    cout << "False at nxt % 2 == level % 2" << endl;
                    return false;
                }
                if (level % 2 == 0) {
                    if (nxt <= prev) {
                        cout << "False nxt >= prev" << endl;
                        return false;
                    }                    
                } else {
                    if (nxt >= prev) {
                        cout << "False nxt <= prev" << level << endl;
                        return false;
                    }
                }
                prev = nxt;
                if (frt->left) {
                    q.push(frt->left);
                }
                if (frt->right) {
                    q.push(frt->right);
                }                
                sz--;
            }
            level++;
        }
        return true;
    }
};

int main() {
    string tree = "[1,10,4,3,null,7,9,12,8,6,null,null,2]";
    TreeNode *root = stringToTreeNode(tree);
    cout << Solution().isEvenOddTree(root) << endl;
    return 0;
}