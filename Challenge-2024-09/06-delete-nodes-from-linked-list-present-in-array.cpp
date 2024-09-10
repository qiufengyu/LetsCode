#include "../header.h"

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode *dummy = new ListNode{0, nullptr};
        ListNode *current = dummy;
        unordered_set<int> st(nums.begin(), nums.end());
        while (head != nullptr) {
            if (st.count(head->val) == 0) {
                current->next = head;
                current = head;
            }
            head = head->next;
        }
        current->next = nullptr;
        return dummy->next;
    }
};

int main() {
    ListNode *n4 = new ListNode{4, nullptr};
    ListNode *n3 = new ListNode{3, n4};
    ListNode *n2 = new ListNode{2, n3};
    ListNode *n1 = new ListNode{1, n2};
    vector<int> nums = {5};
    ListNode *res = Solution().modifiedList(nums, n1);
    prettyPrintLinkedList(res);
    return 0;
}