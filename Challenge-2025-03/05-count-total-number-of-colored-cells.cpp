#include "../header.h"

class Solution {
public:
    long long coloredCells(int n) {
        long long res = (long long)n;
        return 1LL + 2LL * n * (n - 1LL);
    }
};