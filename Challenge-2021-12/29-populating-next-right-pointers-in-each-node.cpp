#include "../header.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root != nullptr) {
            q.push(root);
            while (!q.empty()) {
                int sz = q.size();
                Node *prev = q.front();
                if (prev->left) {
                    q.push(prev->left);
                }
                if (prev->right) {
                    q.push(prev->right);
                }
                q.pop();
                for (int i = 1; i < sz; ++i) {
                    Node *current = q.front();
                    q.pop();
                    if (current->left) {
                        q.push(current->left);
                    }
                    if (current->right) {
                        q.push(current->right);
                    }
                    prev->next = current;
                    prev = current;
                }
                prev->next = nullptr;
            }
        }
        return root;
    }
};