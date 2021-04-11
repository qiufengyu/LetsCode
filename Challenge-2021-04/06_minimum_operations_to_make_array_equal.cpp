#include "../header.h"

class Solution {
public:
    int minOperations(int n) {
        int m = n / 2;
        int a1 = n - 1;
        return (m * a1) + m - m * m;        
    }
};

// The result is the sum of an arithmetic sequence, whose a1 = n - 1, d = -2, #items = n / 2