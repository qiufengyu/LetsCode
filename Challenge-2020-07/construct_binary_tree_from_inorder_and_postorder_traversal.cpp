#include "../header.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int nodes = inorder.size() - 1;
        int current = nodes;
        return build(inorder, postorder, 0, nodes, &current);
    }

    TreeNode* build(const vector<int>& inorder, const vector<int>& postorder, int start, int end, int* current) {
        if (start > end) {
            return nullptr;
        }
        TreeNode *tn = new TreeNode(postorder[*current]);
        (*current)--;
        if (start == end) {
            return tn;
        }
        int i = search(inorder, start, end, tn->val);        
        tn->right = build(inorder, postorder, i + 1, end, current);
        tn->left = build(inorder, postorder, start, i - 1, current);
        return tn;
    }

    int search(const vector<int>& inorder, int start, int end, int value) { 
        int i = start; 
        for (; i <= end; i++) { 
            if (inorder[i] == value) 
                break; 
        } 
        return i; 
    } 
};

int main() {
    vector<int> inorder {9,3,15,20,7};
    vector<int> postorder {9,15,7,20,3};
    TreeNode *root = Solution().buildTree(inorder, postorder);
    prettyPrintTree(root);
    return 0;
}