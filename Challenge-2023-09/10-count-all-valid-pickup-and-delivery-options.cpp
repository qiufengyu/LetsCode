#include "../header.h"

int const M = 1000000007;

class Solution {
public:
    int countOrders(int n) {
        long long res = 1LL;
        for (int i = 1; i <= n; i++) {
            long long temp = ((2 * i) * (2 * i - 1) / 2) % M;
            res = (res * temp) % M;
        }
        return (int)res;
    }
};