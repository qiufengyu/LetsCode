#include "../header.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int l = 0;
        ListNode* t = head;
        while (t) {
            l++;
            t = t->next;
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy, *current = head, *temp = nullptr;
        ListNode *tempHead = prev, *tempTail = prev->next;
        for (int i = 0; i < l / k; ++i) {
            for (int j = 0; j < k - 1; ++j) {
                temp = current->next;
                current->next = prev;
                prev = current;
                current = temp;
            }
            temp = current->next;
            current->next = prev;
            prev = tempTail;
            tempHead->next = current;
            current = temp;
            tempHead = tempTail;
            tempTail->next = current;
            tempTail = temp;
        }
        return dummy->next;
    }
};

int main() {
    ListNode *head = stringToListNode("[1,2,3,4,5]");
    int k = 2;
    prettyPrintLinkedListWithSize(Solution().reverseKGroup(head, k), 10);
    return 0;
}
