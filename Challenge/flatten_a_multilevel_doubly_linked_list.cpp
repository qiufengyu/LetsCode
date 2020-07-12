#include "header.h"

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
        Node *start = head;
        Node *n = head;
        stack<Node *> s;        
        while (n != nullptr) {
            Node *c = n->child;
            Node *nxt = n->next;         
            if (c != nullptr) {
                n->next = c;
                c->prev = n;
                if (nxt) {
                    s.push(nxt);
                }                
            } else if (nxt != nullptr && c == nullptr) {
                n->next = nxt;
                nxt->prev = n;
            } else if (nxt == nullptr) {
                if (!s.empty()) {
                    Node *temp = s.top();
                    n->next = temp;
                    temp->prev = n;
                    s.pop();
                } else {
                    n->next = nullptr;                    
                }
            }
            n->child = nullptr;
            n = n->next;
        }
        return start;
    }
};

int main() {

}