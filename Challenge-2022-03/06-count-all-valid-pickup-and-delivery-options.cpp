#include "../header.h"

class Solution {
public:
    int countOrders(int n) {
        int const M = 1000000007;
        long long res = 1;
        for (int i = 1; i <= n; ++i) {
            res *= i;
            res %= M;
            res *= (2 * i - 1);
            res %= M;
        }
        return res % M;
    }
};
