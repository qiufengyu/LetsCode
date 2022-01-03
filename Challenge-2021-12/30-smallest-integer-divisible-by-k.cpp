#include "../header.h"

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int l = k % 10;
        if (l == 1 || l == 3 || l == 7 || l == 9) {
            int n = 0;
            for (int i = 1; i <= k; ++i) {
                n = (n * 10 + 1) % k;
                if (n == 0) {
                    return i;
                }
            }
        }
        return -1;
    }
};