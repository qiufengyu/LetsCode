#include "../header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, curMin = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            curMin = min(curMin, prices[i]);
            res = max(res, prices[i] - curMin);
        }
        return res;
    }
};