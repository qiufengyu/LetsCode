#include "../header.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        Node* current = head;
        while (current) {
            if (current->child) {
                Node* nxt = current->next;
                Node* cld = current->child;
                while (cld->next) {
                    cld = cld->next;
                }
                current->next = current->child;
                current->child->prev = current;
                current->child = nullptr; // no child!
                cld->next = nxt;
                if (nxt) {
                    nxt->prev = cld;
                }
            }
            current = current->next;
        }
        return head;
    }
};