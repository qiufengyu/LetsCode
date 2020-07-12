#include "header.h"

struct TreeOrder {
    TreeNode *node;
    unsigned long order;
    TreeOrder(TreeNode *n, unsigned long o) : node(n), order(o) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        deque<TreeOrder*> q;
        int ans = 0;
        if (root == nullptr) {
            return 0;
        }
        q.push_back(new TreeOrder {root, 0});
        while (!q.empty()) {
            int sz = q.size();
            int temp = q.back()->order - q.front()->order;
            if (temp > ans) {
                ans = temp;
            }
            for (int i = 0; i < sz; i++) {
                TreeOrder *to = q.front();
                if (to->node->left != nullptr) {
                    q.push_back(new TreeOrder {to->node->left, 2 * to->order + 1});
                }
                if (to->node->right != nullptr) {
                    q.push_back(new TreeOrder {to->node->right, 2 * to->order + 2});
                }
                q.pop_front();
            }
        }
        return ans + 1;
    }
};

int main() {
    string t {"[1,3,2,5,null,null,null]"};
    TreeNode* root = stringToTreeNode(t);
    cout << Solution().widthOfBinaryTree(root) << endl;
    return 0;    
}