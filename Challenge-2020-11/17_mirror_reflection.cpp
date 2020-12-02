#include "../header.h"

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int k = 1;
        while (p * k % q) {
            k++;
        }
        if (k % 2 == 0) {
            return 0;
        } else {
            int r = p * k / q;
            return r % 2 ?  1 : 2;
        }
    }
};