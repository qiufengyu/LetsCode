#include <iostream>
#include <queue>
using namespace std;


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

struct TreeRelation {
    TreeNode* parent;
    TreeNode* child;
    int level;
    TreeRelation(TreeNode* p, TreeNode* c, int l): parent(p), child(c), level(l) {}
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeRelation*> q;
        TreeNode* node = root;
        TreeRelation* rel = new TreeRelation(nullptr, root, 0);
        TreeRelation* cur = nullptr;
        int findXY = 0; // 1->X, 2->Y
        q.push(rel);
        while (!q.empty()) {
            rel = q.front();
            q.pop();
            node = rel->child;
            if (node->val == x) {
                findXY = 2;
                cur = rel;
                break;
            }
            if (node->val == y) {
                findXY = 1;
                cur = rel;
                break;
            }
            if (node->left) {
                q.push(new TreeRelation(node, node->left, rel->level+1));
            }
            if (node->right) {
                q.push(new TreeRelation(node, node->right, rel->level+1));
            }
        }
        if (findXY == 1) {
            // find X
            while (!q.empty()) {
                rel = q.front();
                q.pop();
                if (rel->child->val == x && rel->level == cur->level && rel->parent->val != cur->parent->val ) {
                    return true;
                }
            }
        }
        if (findXY == 2) {
            while (!q.empty()) {
                rel = q.front();
                q.pop();
                if (rel->child->val == y && rel->level == cur->level && rel->parent->val != cur->parent->val ) {
                    return true;
                }
            }
        }    
        return false;
    }
};

int main() {
    char c;
    while(cin.get(c)) {
        cout.put(c);
    }
    return 0;
}