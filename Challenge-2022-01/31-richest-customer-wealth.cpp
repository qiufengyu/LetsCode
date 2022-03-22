// Chinese New Year Eve
// Be Rich!

#include "../header.h"

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for (vector<int> const& account: accounts) {
            res = max(res, accumulate(account.begin(), account.end(), 0));
        }
        return res;
    }
};