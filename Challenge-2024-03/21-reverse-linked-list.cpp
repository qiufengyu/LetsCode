#include "../header.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *current = head, *prev = nullptr;
        while (current) {
            ListNode *nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }
        return prev;
    }
};

int main() {
    string s {"[1,2,3,4,5]"};
    ListNode* head = stringToListNode(s);
    ListNode* res = Solution().reverseList(head);
    prettyPrintLinkedList(res);
    return 0;
}