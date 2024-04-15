#include "../header.h"

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = tickets[k];
        int t = tickets[k];
        for (int i = 0; i < k; i++) {
            res += min(tickets[i], t);
        }
        for (int i = k + 1; i < tickets.size(); i++) {
            res += min(tickets[i], t - 1);
        }
        return res;
    }
};