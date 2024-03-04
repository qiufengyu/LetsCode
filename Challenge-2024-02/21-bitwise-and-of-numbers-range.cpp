#include "../header.h"

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int bits = 0;
        while (left != right) {
            bits++;
            left >>= 1;
            right >>= 1;
        }
        return (left << bits);
    }
};