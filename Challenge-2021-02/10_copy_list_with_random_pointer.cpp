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
        Node* n = head;
        while (n) {
          Node *t = new Node(n->val);
          t->next = n->next;
          n->next = t;
          n = t->next;
        }
        n = head;
        while (n) {
          if (n->random) {
            n->next->random = n->random->next;
          }
          n = n->next->next;
        }
        n = head;
        Node *res = head->next;
        while (n) {
          Node *t = n->next;
          n->next= t->next;
          if (t->next) {
            t->next = t->next->next;
          }
          n = n->next;
        }
        return res;
    }
};