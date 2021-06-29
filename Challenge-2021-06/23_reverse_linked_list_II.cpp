#include "../header.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *h = new ListNode(0);
        h->next = head;
        ListNode *prev = h, *current = head;
        int i = 1;
        while (i < left && current != nullptr) {
            ++i;
            prev = current;
            current = current->next;
        }
        // reverse from current to right
        ListNode *rhead = current, *temp = current;
        while (i <= right && current != nullptr) {
            ++i;
            ListNode *ntemp = temp->next;
            temp->next = current;
            current = temp;
            temp = ntemp;
        }
        rhead->next = temp;        
        prev->next = current;
        return h->next;
    }
};

int main() {
    string s;
    cin >> s;
    int l, r;
    cin >> l >> r;
    ListNode *head = stringToListNode(s);
    ListNode *result = Solution().reverseBetween(head, l, r);
    prettyPrintLinkedList(result);
    return 0;
}