#include "../header.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class NodeCount {
private:
    vector<int> m;
public:
    NodeCount(): m(10, 0) {}
    void push(int n) {
        m[n]++;
    }

    void pop(int n) {
        m[n]--;
    }
    
    bool isPseudoPalindromic() {
        int count = 0;
        for (int i = 1; i < 10; i++) {
            if (m[i] & 1 == 1) {
                count++;
            }
        }
        return count <= 1;
    }
};

class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int res = 0;
        NodeCount *nc = new NodeCount();
        if (root)
            helper(root, res, nc);
        return res;
    }

    void helper(TreeNode* node, int& res, NodeCount* nc) {
        nc->push(node->val);
        if (node->left || node->right) {
            if (node->left) helper(node->left, res, nc);
            if (node->right) helper(node->right, res, nc);
        } else if (nc->isPseudoPalindromic()) {
            res++;
        }
        nc->pop(node->val);
    }
};
