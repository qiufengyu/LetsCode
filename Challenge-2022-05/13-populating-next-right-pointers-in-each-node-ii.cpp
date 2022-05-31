#include "../header.h"


// Definition for a Node.
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
        Node *head = nullptr, *prev = nullptr, *current = root;
        while (current != nullptr) {
            while (current != nullptr) {
                if (current->left != nullptr) {
                    if (prev != nullptr) {
                        prev->next = current->left;
                    } else {
                        head = current->left;
                    }
                    prev = current->left;
                }
                if (current->right != nullptr) {
                    if (prev != nullptr) {
                        prev->next = current->right;
                    } else {
                        head = current->right;
                    }
                    prev = current->right;
                }
                current = current->next;
            }
            // to next level
            current = head;
            prev = nullptr;
            head = nullptr;
        }
        return root;
    }
};