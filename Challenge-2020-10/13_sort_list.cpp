#include "../header.h"

class Solution2 {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummyHead(0);
        ListNode* ptr = &dummyHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        if(list1) ptr->next = list1;
        else ptr->next = list2;

        return dummyHead.next;
    }

    ListNode* getMid(ListNode* head) {
        ListNode* midPrev = nullptr;
        while (head && head->next) {
            midPrev = (midPrev == nullptr) ? head : midPrev->next;
            head = head->next->next;
        }
        ListNode* mid = midPrev->next;
        midPrev->next = nullptr;
        return mid;
    }
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        quickSortList(head, nullptr);
        return head;
    }

    void quickSortList(ListNode* head, ListNode* tail) {
        if (head != tail && head->next != nullptr) {
            ListNode *mid = partition(head, tail);
            quickSortList(head, mid);
            quickSortList(mid->next, tail);
        }
    }

    ListNode* partition(ListNode* head, ListNode* tail) {
        int v = head->val;
        ListNode *current = head;
        for (ListNode *n = head->next; n != tail; n = n->next) {
            if (n->val < v) {
                current = current->next;
                swap(n->val, current->val);
            }
        }
        swap(current->val, head->val);
        return current;
    }
};