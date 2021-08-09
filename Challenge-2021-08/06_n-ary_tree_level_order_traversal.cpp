#include "../header.h"

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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root != nullptr) {
            queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                vector<int> v;
                int sz = q.size();
                while (sz > 0) {
                    Node *n = q.front();
                    q.pop();
                    v.push_back(n->val);
                    for (auto c: n->children) {
                        q.push(c);
                    }
                    sz--;
                }
                res.push_back(v);
            }
        }
        return res;        
    }
};