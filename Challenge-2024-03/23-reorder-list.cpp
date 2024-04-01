#include "../header.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head && head->next) {
            ListNode *slow = head, *fast = head, *p = head;
            while (fast && fast->next) {
                p = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            // break the link between two parts
            p->next = nullptr;
            // slow points to the start of the second half
            // reverse second half
            ListNode *current = slow, *prev = nullptr;
            while (current) {
                ListNode *nxt = current->next;
                current->next = prev;
                prev = current;
                current = nxt;
            }
            prettyPrintLinkedListWithSize(head, 10);
            prettyPrintLinkedListWithSize(prev, 10);
            //merge n1 and reversed n2
            ListNode *n1 = head, *n2 = prev;
            while (n1 && n2) {
                ListNode *tmp1 = n1->next;
                ListNode *tmp2 = n2->next;
                n1->next = n2;
                n2->next = tmp1 == nullptr ? tmp2 : tmp1;
                n1 = tmp1;
                n2 = tmp2;
            }
        }
    }
};

int main() {
    string s {"[1,2,3,4,5]"};
    ListNode *head = stringToListNode(s);
    prettyPrintLinkedList(head);
    Solution().reorderList(head);
    prettyPrintLinkedListWithSize(head, 10);
    return 0;
}