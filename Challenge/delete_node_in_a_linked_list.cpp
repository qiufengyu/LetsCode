#include "header.h"

class Solution {
public:
    void deleteNode(ListNode* node) {
        // node->val = node->next->val;
        // node->next = node->next->next;
        ListNode* next = node->next;
        while (next) {
            node->val = next->val;
            if (next->next) {
                node = next;
                next = next->next;
            } else {
                node->next = nullptr;
                delete next;
                next = nullptr;
            }        
        }
    }
};

int main() {
    string line;
    getline(cin, line);
    ListNode *head = stringToListNode(line);
    prettyPrintLinkedList(head);
    ListNode *del = head;
    del = del->next->next->next;
    Solution().deleteNode(del);
    prettyPrintLinkedList(head);
    return 0;
}