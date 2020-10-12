#include "../header.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        int l = 0;
        ListNode *cur = head;
        ListNode *prev = nullptr;
        while (cur != nullptr) {
            l++;
            prev = cur;
            cur = cur->next;
        }
        prev->next = head;
        int rest = l - k % l;
        for (int i = 0; i < rest; i++) {
            prev = prev->next;
        }
        ListNode *newHead = prev->next;
        prev->next = nullptr;
        return newHead;
    }
};

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    ListNode *head = stringToListNode(s);
    ListNode *node = Solution().rotateRight(head, k);
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
    return 0;
}