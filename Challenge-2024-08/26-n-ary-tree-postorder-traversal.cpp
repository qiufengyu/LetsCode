#include "../header.h"

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }

    void traversal(Node* node, vector<int>& res) {
        if (node) {
            for (auto const& child: node->children) {
                traversal(child, res);
            }            
            res.push_back(node->val);
        }
    }
};