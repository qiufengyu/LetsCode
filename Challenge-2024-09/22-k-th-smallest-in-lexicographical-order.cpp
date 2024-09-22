#include "../header.h"

class Solution {
public:
    int findKthNumber(int n, int k) {
        long num = 1, i = 1;
        while (i < k) {
            int r = getNum(num, num + 1, n);
            if (i + r <= k) {
                i += r;
                num++;
            } else {
                i++;
                num *= 10;
            }
        }
        return num;
    }

    int getNum(long a, long b, int const& n) {
        int step = 0;
        while (a <= n) {
            step += min((long)n + 1, b) - a;
            a *= 10;
            b *= 10;
        }
        return step;
    }
};