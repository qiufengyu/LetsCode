#include "../header.h"

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        ListNode *node = head;
        int round = 1;
        while (node != nullptr) {
            if (round == m && round == n) {
                res[round / 2][round / 2] = node->val;
                node = node->next;
            }
            for (int i = round / 2; i < n - round / 2 - 1 && node != nullptr; i++) {
                res[round / 2][i] = node->val;
                node = node->next;
            }
            for (int i = round / 2; i < m - round / 2 - 1 && node != nullptr; i++) {
                res[i][n - round / 2 - 1] = node->val;
                node = node->next;
            }
            for (int i = n - round / 2 - 1; i > round / 2 && node != nullptr; i--) {
                res[m - round / 2 - 1][i] = node->val;
                node = node->next;
            }
            for (int i = m - round / 2 - 1; i > round / 2 && node != nullptr; i--) {
                res[i][round / 2] = node->val;
                node = node->next;
            }
            round += 2;
        }
        return res;
    }
};

int main() {
    int m = 1, n = 4;
    ListNode *head = stringToListNode("[0,1,2]");
    auto res = Solution().spiralMatrix(m, n, head);
    print_vector<int>(res);
    return 0;
}