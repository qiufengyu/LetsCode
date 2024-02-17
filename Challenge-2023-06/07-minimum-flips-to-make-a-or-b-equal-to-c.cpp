#include "../header.h"

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int aOrb = a | b;
            if (c % 2 == 0) {
                if (aOrb % 2 != 0) {
                    res += (a % 2 != 0) + (b % 2 != 0);
                }
            } else if (aOrb % 2 == 0) {
                res += 1;
            }            
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return res;        
    }
};