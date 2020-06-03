#include <iostream>
#include <stack>
using namespace std;


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode *current = root;
        int count = 0;
        while (!s.empty() || current ) {
            while (current) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            count++;
            if (count == k) {
                return current->val;
            }
            current = current->right;
            
        }
        return root->val;
    }
};

int main() {
    TreeNode *root = new TreeNode(5);
    TreeNode *l1_1 = new TreeNode(3);
    TreeNode *l1_2 = new TreeNode(6);
    TreeNode *l2_1 = new TreeNode(2);
    TreeNode *l2_2 = new TreeNode(4);
    TreeNode *l3_1 = new TreeNode(1);
    root->left = l1_1;
    root->right = l1_2;
    l1_1->left = l2_1;
    l1_1->right = l2_2;
    l2_1->left = l3_1;
    cout << Solution().kthSmallest(root, 3) << endl;
    return 0;
}
