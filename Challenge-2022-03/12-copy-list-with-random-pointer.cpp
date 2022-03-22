#include "../header.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }
        Node *current = head, *nxt = head;
        while (current != nullptr) {
            nxt = current->next;
            Node *n = new Node(current->val);
            current->next = n;
            n->next = nxt;
            current = nxt;
        }
        current = head;
        while (current != nullptr) {
            if (current->random != nullptr) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }
        current = head;
        Node *res = current->next;
        nxt = res;
        while (nxt != nullptr) {
            current->next = current->next->next;
            current = current->next;
            if (nxt->next != nullptr) {
                nxt->next = nxt->next->next;
            }
            nxt = nxt->next;
        }
        return res;
    }
};