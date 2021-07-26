#include "../header.h"

class Solution {
public:
    int findIntegers(int n) {
        int f[32] = {0};
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; ++i) {
            f[i] = f[i-1] + f[i-2];
        }
        int i = 30, res = 0;
        bool prev = 0;
        while (i >= 0) {
            if ((n & (1 << i)) != 0) {
                res += f[i];
                if (prev) {
                    res--;
                    break;
                }
                prev = true;
            } else {
                prev = false;
            }
            i--;
        }
        return res + 1;
    }
};