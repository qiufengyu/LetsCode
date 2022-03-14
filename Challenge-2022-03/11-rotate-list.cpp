#include "../header.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr) {
            return head;
        }
        ListNode *prev = head, *current = head;
        int l = 0;
        while (current != nullptr) { 
            ++l;
            current = current->next;
        }
        if (l == 1 || (k % l == 0)) {
            return head;
        }
        current = head;
        k = l - k % l;
        while (k > 0) {
            --k;
            prev = current;
            current = current->next;
        }
        ListNode *t = current;
        while (t->next != nullptr) {
            t = t->next;
        }
        t->next = head;
        prev->next = nullptr;
        return current;
    }
};

int main() {
    string s;
    int k;
    cin >> s;
    cin >> k;
    ListNode *head = stringToListNode(s);
    ListNode *res = Solution().rotateRight(head, k);
    prettyPrintLinkedList(res);
    return 0;
}