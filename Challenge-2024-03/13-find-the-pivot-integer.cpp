#include "../header.h"

class Solution {
public:
    int pivotInteger(int n) {
        int x = (int)sqrt((n * n + n) / 2.0);
        if (2 * x * x == n * (n + 1)) {
            return x;
        }
        return -1;
    }
};