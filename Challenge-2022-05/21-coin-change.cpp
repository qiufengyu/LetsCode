#include "../header.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res(amount + 1, INT_MAX);
        res[0] = 0;
        int n = coins.size();
        for (int i = 0; i < n; ++i) {
            if (coins[i] <= amount) {
                res[coins[i]] = 1;
            }
        }
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < n; ++j) {
                if (coins[j] < i && res[i - coins[j]] != INT_MAX) {
                    res[i] = min(res[i], res[i - coins[j]] + 1);
                }
            }
        }
        return res[amount] == INT_MAX ? -1 : res[amount];
    }
};