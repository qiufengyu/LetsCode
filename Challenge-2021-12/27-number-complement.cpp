#include "../header.h"

class Solution {
public:
    int findComplement(int num) {
        unsigned M = 0xffffffff & num;
        unsigned mask = 0;
        while (num != 0) {
            mask = mask * 2 + 1;
            num >>= 1;
        }
        return (mask & (~M));
    }
};