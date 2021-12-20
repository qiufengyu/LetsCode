#include "../header.h"

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* node = head->next;
        ListNode* prev = dummy, *current = head, *temp = node;
        current->next = nullptr;
        while (node != nullptr) {
            prev = dummy;
            current = dummy->next;
            while (current != nullptr && current->val <= node->val) {
                prev = current;
                current = current->next;        
            }
            temp = node->next;
            prev->next = node;
            node->next = current;
            node = temp;
        }        
        return dummy->next;
    }
};

int main() {
    string s;
    cin >> s;
    ListNode* head = stringToListNode(s);
    ListNode* result = Solution().insertionSortList(head);
    prettyPrintLinkedList(result);
    return 0;
}