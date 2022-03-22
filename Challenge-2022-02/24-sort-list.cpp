#include "../header.h"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode *res = mergeSort(head, nullptr);
        return res;
    }

    ListNode* mergeSort(ListNode *head, ListNode* tail) {
        // length = 0
        if (head == nullptr) {
            return nullptr;
        }
        // length = 1
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        // find mid
        ListNode *slow = head, *fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        ListNode *mid = slow;
        ListNode *n1 = mergeSort(head, mid);
        ListNode *n2 = mergeSort(mid, tail);
        ListNode *sorted = merge(n1, n2);
        return sorted;
    }

    ListNode* merge(ListNode *n1, ListNode *n2) {
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy, *t1 = n1, *t2 = n2;
        while (t1 != nullptr && t2 != nullptr) {
            if (t1->val < t2->val) {
                temp->next = t1;
                t1 = t1->next;
            } else {
                temp->next = t2;
                t2 = t2->next;
            }
            temp = temp->next;
        }
        if (t1 != nullptr) {
            temp->next = t1;
        }
        if (t2 != nullptr) {
            temp->next = t2;
        }
        return dummy->next;
    }
};
