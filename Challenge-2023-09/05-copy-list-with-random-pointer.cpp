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
            return nullptr;
        }
        Node *n = head;
        while (n) {
            Node *nn = new Node{n->val};
            nn->next = n->next;
            n->next = nn;
            n = nn->next;
        }
        n = head;
        while (n) {
            if (n->random) {
                n->next->random = n->random->next;
            }
            n = n->next->next;
        }
        n = head;
        Node *nn = head->next;
        Node *np = n, *nnp = nn;
        while (np) {
            np->next = nnp->next;
            nnp->next = nnp->next == nullptr ? nullptr : nnp->next->next;
            np = np->next;
            nnp = nnp->next;
        }
        return nn;
    }
};