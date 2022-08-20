#include "../header.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int sign = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1;
        long a = labs(dividend), b = labs(divisor), res = 0;
        while (a >= b) {
            long temp = b, m = 1;
            while ((temp << 1) <= a) {
                temp <<= 1;
                m <<= 1;
            }
            a -= temp;
            res += m;
        }
        return sign * res;        
    }
};