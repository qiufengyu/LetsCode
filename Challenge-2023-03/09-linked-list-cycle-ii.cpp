#include "../header.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *res = head;
                while (res != fast) {
                    res = res->next;
                    fast = fast->next;
                }
                return res;
            }
        }
        return nullptr;        
    }
};

int main() {
    string s;
    cin >> s;
    ListNode *head = stringToListNode(s);
    int n;
    cin >> n;
    ListNode *t = head;
    while (n > 0) {
        t = t->next;
        --n;
    }
    ListNode *p = head;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = t;
    ListNode* res = Solution().detectCycle(head);
    cout << res->val << endl;
    return 0;
}
