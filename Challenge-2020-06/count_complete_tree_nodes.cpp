#include "header.h"

class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> q;
        int count = 0;
        if (root == nullptr) {
            return count;
        }
        q.push(root);
        while (!q.empty()) {
            TreeNode *n = q.front();
            q.pop();
            count++;
            if (n->left) {
                q.push(n->left);
            } else {
                count += q.size();
                return count;
            }
            if (n->right) {
                q.push(n->right);
            } else {
                count += q.size();
                return count;
            }
        }
        return count;
    }
};

int main() {

}