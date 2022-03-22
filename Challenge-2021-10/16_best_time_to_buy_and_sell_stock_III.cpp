#include "../header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if (sz == 0) {
            return 0;
        }
        vector<vector<int>> global(sz, vector<int>(3, 0));
        vector<vector<int>> local(sz, vector<int>(3, 0));
        for (int i = 1; i < sz; i++) {
            int diff = prices[i] - prices[i-1];
            for (int j = 1; j < 3; j++) {
                local[i][j] = max(global[i-1][j-1] + max(diff, 0), local[i-1][j] + diff);
                global[i][j] = max(local[i][j], global[i-1][j]);
            }
        }
        return global[sz-1][2];
    }
};