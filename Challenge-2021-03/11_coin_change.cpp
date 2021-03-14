#include "../header.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int c[10001];
        c[0] = 0;
        int sz = coins.size();
        for (int i = 1; i <= amount; i++) {
            c[i] = 10001;
        }
        for (const int coin: coins) {
            if (coin <= amount) {
                c[coin] = 1;
            }
        }
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < sz; j++) {
                if (coins[j] < i) {
                    c[i] = min(c[i], c[i-coins[j]] + 1);
                }
            }
        }
        return c[amount] >= 10001 ? -1 : c[amount];
    }
};