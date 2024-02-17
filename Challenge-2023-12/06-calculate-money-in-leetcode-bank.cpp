#include "../header.h"

class Solution {
public:
    int totalMoney(int n) {
        int w = n / 7, d = n % 7;
        int wm = w * 28 + w * (w - 1) / 2 * 7;
        // the rest of days
        int start = 1 + w;
        while (d > 0) {
            wm += start;
            start++;
            d--;
        }
        return wm;
    }
};