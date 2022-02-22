#include "../header.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *current = head, *nxt = head->next;
        while (current != nullptr && nxt != nullptr) {
            ListNode *tmp = nxt->next;
            prev->next = nxt;
            nxt->next = current;
            current->next = tmp;
            prev = current;
            current = tmp;
            if (tmp != nullptr) {
                nxt = tmp->next;
            }
        }
        return dummy->next;        
    }
};

int main() {
    string s;
    cin >> s;
    ListNode *head = stringToListNode(s);
    ListNode *res = Solution().swapPairs(head);
    prettyPrintLinkedList(res);
    return 0;
}