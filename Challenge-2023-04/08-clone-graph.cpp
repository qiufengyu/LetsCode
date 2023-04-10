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
public:
    Node* cloneGraph(Node* node) {
        map<int, Node*> m;
        Node* n = clone(node, m);
        return n;
    }

    Node* clone(Node* node, map<int, Node*>& m) {
        int v = node->val;
        if (m.count(v) == 0) {
            Node *n = new Node(v);
            m.insert({v, n});
            for (auto nn: node->neighbors) {
                Node* nr = clone(nn, m);
                n->neighbors.push_back(nr);
            }
            return n;
        } else {
            return m[v];
        }
    }
};

int main() {
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n4);
    n2->neighbors.push_back(n1);
    n2->neighbors.push_back(n3);
    n3->neighbors.push_back(n2);
    n3->neighbors.push_back(n4);
    n4->neighbors.push_back(n1);
    n4->neighbors.push_back(n3);
    Node *res = Solution().cloneGraph(n1);
    cout << res->val << endl;
    for (auto n: res->neighbors) {
        cout << n->val << endl;
        for (auto nn: n->neighbors) {
            cout << nn->val << endl;
        }
    }
    return 0;
}