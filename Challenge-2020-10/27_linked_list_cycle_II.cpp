#include "../header.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool flag = false;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                flag = true;
                break;
            }
        }
        if (flag) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        return nullptr;
    }
};

int main() {
    string s;
    cin >> s;
    ListNode *head = stringToListNode(s);
    ListNode *tail = head;
    while (tail && tail->next) {
        tail = tail->next;
    }
    int pos = 0;
    cin >> pos;   
    if (pos >= 0) {
        ListNode *current = head;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        tail->next = current;
    }
    ListNode *entry = Solution().detectCycle(head);
    if (entry) {
        cout << entry->val << endl;
    } else {
        cout << "No cycle" << endl;
    }
    return 0;
}