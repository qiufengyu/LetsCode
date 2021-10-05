#include "../header.h"

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *h = head;
        int n = 0;
        vector<ListNode*> res(k, nullptr);
        while (h != nullptr) {
            ++n;
            h = h->next;
        }
        int g = n / k, r = n % k;
        h = head;
        ListNode *prev = nullptr;
        for (int i = 0; i < k; ++i) {
            res[i] = h;
            for (int j = 0; j < g; ++j) {
                prev = h;
                h = h->next;
            }
            if (i < r) {
                prev = h;
                h = h->next;
            }
            if (prev) prev->next = nullptr;
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    ListNode *head = stringToListNode(s);
    auto res = Solution().splitListToParts(head, k);
    for (auto const n: res) {
        prettyPrintLinkedList(n);
    }
    return 0;
}