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
        queue<Node*> q;
        vector<vector<int>> res;
        if (root) {
            q.push(root);
            while (!q.empty()) {
                int sz = q.size();
                vector<int> v;
                while (sz > 0) {
                    Node* n = q.front();
                    q.pop();
                    v.push_back(n->val);
                    for (auto c: n->children) {
                        q.push(c);
                    }
                    --sz;
                }
                res.push_back(v);
            }
        }
        return res;        
    }
};