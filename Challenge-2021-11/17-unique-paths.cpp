#include "../header.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        return nCr(m+n-2, min(m-1, n-1)); 
    }

    int nCr(int n, int r) {
        long long f = 1L;
        long long ff = 1L;
        int rr = r;
        for (int i = 0; i < r; i++) {
            f *= n; ff *= rr;
            n--; rr--;
        }
        return int(f / ff);
    }
};
