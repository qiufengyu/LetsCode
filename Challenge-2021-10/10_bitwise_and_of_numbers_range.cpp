#include "../header.h"

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int round = 0;
        while (left != right) {
            ++round;
            left >>= 1;
            right >>= 1;
        }
        return (left << round);
    }
};