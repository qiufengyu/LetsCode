#include "../header.h"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddStart = nullptr, *evenStart = nullptr;
        ListNode *current = head, *co = nullptr, *ce = nullptr;
        int count = 0;
        while (current != nullptr) {
            ++count;
            if (count % 2 == 0) {
                if (evenStart == nullptr) {
                    evenStart = current;
                    ce = evenStart;
                } else {
                    ce->next = current;
                    ce = ce->next;
                }
            } else {
                if (oddStart == nullptr) {
                    oddStart = current;
                    co = oddStart;
                } else {
                    co->next = current;
                    co = co->next;
                }
            }
            current = current->next;
        }
        if (oddStart == nullptr) {
            return evenStart;
        }
        if (ce != nullptr) {
            ce->next = nullptr;
        }
        co->next = evenStart;
        return oddStart;
    }
};

int main() {
    string s;
    cin >> s;
    ListNode *head = stringToListNode(s);
    ListNode *res = Solution().oddEvenList(head);
    prettyPrintLinkedList(res);
    return 0;
}