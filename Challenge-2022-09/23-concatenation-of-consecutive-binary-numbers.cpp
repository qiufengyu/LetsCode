#include "../header.h"

int const M = 1000000007;

class Solution {
public:
    int concatenatedBinary(int n) {
        int i = 1;
        long long res = 0L;
        while (i <= n) {
            res = ((res << ((int)log2(i) + 1)) + i ) % M;
            ++i;
        }
        return (int)res;
    }
};