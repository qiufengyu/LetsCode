#include "../header.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow points to the mid of the second half
        // reverse second half
        ListNode *current = slow, *prev = nullptr;
        while (current) {
            ListNode *nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }
        ListNode *n = head;
        while (n && prev) {
            cout << n->val << " - " << prev->val << endl; 
            if (n->val != prev->val) {
                return false;
            }
            n = n->next;
            prev = prev->next;
        }
        return true;
    }
};

int main() {
    string s = "[1,2,2,1]";
    ListNode *head = stringToListNode(s);
    cout << Solution().isPalindrome(head) << endl;
    return 0;
}