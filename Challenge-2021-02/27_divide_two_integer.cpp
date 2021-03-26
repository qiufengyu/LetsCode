#include "../header.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) { 
            return INT_MAX;
        }
        long m = labs(dividend), n = labs(divisor);
        long res = 0;
        bool sign = !((divisor > 0) ^ (dividend > 0));
        if (n == 1) {
            return sign ? m : -m;
        }
        while (m >= n) {
            long t = n, p = 1;
            while (m >= (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            m -= t;
        }
        return sign ? res : -res;
    }
};