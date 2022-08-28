#include "../header.h"

class Solution {
public:
    bool isPowerOfThree(int n) {
        int m = 1162261467; // 3^19, 3^20 = 3486784401 > MaxInt32
        return n > 0 && (m % n == 0);
    }
};
