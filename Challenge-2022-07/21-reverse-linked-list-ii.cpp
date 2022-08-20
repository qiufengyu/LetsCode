#include "../header.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = head, *prev = dummy;
        int i = 1;
        while (i < left) {
            prev = current;
            current = current->next;
            ++i;
        }
        // reverse from left to right
        ListNode *nxt = current->next;
        while (i < right && nxt) {
            ListNode *nnxt = nxt->next;
            nxt->next = current;
            current = nxt;
            nxt = nnxt;
            ++i;
        }
        prev->next->next = nxt;
        prev->next = current;
        return dummy->next;
    }
};

int main() {
    string s;
    cin >> s;
    int left, right;
    cin >> left >> right;
    ListNode *head = stringToListNode(s);
    ListNode *res = Solution().reverseBetween(head, left, right);
    prettyPrintLinkedList(res);
    return 0;
}