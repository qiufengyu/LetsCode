#include "../header.h"

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
    unordered_map<int, Node*> m;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (m.count(node->val) > 0) {
            return m[node->val];
        }
        Node *newNode = new Node(node->val);
        m[node->val] = newNode;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            Node *t = node->neighbors[i];            
            newNode->neighbors.push_back(cloneGraph(t));
        }
        return newNode;
    }
};