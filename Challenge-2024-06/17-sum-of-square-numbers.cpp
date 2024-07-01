#include "../header.h"

class Solution {
public:
    bool judgeSquareSum(int c) {
        int sqrtC = (int)sqrt(c);
        for (int i = 0; i <= sqrtC; i++) {
            int rest = c - i * i;
            int sqrtRest = (int)(sqrt(rest));
            if (rest == sqrtRest * sqrtRest) {
                return true;
            }
        }
        return false;
    }
};