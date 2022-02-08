#include "../header.h"

class Solution {
    ListNode* mergeTwoList(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                dummy->next = list1;
                list1 = list1->next;
            } else {
                dummy->next = list2;
                list2 = list2->next;
            }
            dummy = dummy->next;
        }
        if (list1) {
            dummy->next = list1;
        }
        if (list2) {
            dummy->next = list2;
        }
        return head->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) {
            return nullptr;
        }
        if (k == 1) {
            return lists[0];
        }
        ListNode* dummy = new ListNode(0);
        int i = 0;
        while (i < k) {
            ListNode *tmp = mergeTwoList(dummy->next, lists[i]);
            dummy->next = tmp;
            ++i;
        }
        return dummy->next;        
    }
};

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    ListNode *l1 = stringToListNode(s1);
    ListNode *l2 = stringToListNode(s2);
    ListNode *l3 = stringToListNode(s3);
    vector<ListNode*> lists {l1, l2, l3};
    ListNode* res = Solution().mergeKLists(lists);
    prettyPrintLinkedList(res);
    return 0;
}